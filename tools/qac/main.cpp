#include <QtCore/qcoreapplication.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qtextstream.h>
#include <QtCore/qjsonvalue.h>
#include <QtCore/qfile.h>
#include <QtCore/qdir.h>
#include <iostream>
#include <cstdlib>

QT_BEGIN_NAMESPACE

class QAC
{
public:
    QAC(const QJsonDocument &doc) : m_doc(doc.object()) { }

    void writeHeader(QTextStream &out)
    {
        writeHeaderOpenGuard(out);
        out << endl;
        writeHeaderIncludes(out);
        out << endl;
        writeBeginNamespace(out);
        out << endl;
        writeClassDeclaration(out);
        out << endl;
        writeEndNamespace(out);
        out << endl;
        writeHeaderCloseGuard(out);
    }

    void writeSource(QTextStream &out)
    {
        writeSourceIncludes(out);
        out << endl;
        writeBeginNamespace(out);
        out << endl;
        writeClassImplementation(out);
        out << endl;
        writeEndNamespace(out);
    }

private:
    void writeHeaderOpenGuard(QTextStream &out)
    {
        const QString name = m_doc.value("class").toString().toUpper();
        out << "#ifndef QQMLANDROID" << name << "_P_H" << endl;
        out << "#define QQMLANDROID" << name << "_P_H" << endl;
    }

    void writeHeaderIncludes(QTextStream &out)
    {
        const QString base = m_doc.value("base").toString().toLower();
        out << "#include \"qtqmlandroidglobal_p.h\"" << endl;
        out << "#include \"qqmlandroid" << base << "_p.h\"" << endl;
        out << "#include <QtAndroidExtras/qandroidjniobject.h>" << endl;
    }

    void writeClassDeclaration(QTextStream &out)
    {
        const QString cls = m_doc.value("class").toString();
        const QString base = m_doc.value("base").toString();
        out << "class QQmlAndroid" << cls << " : public QQmlAndroid" << base << endl;
        out << "{" << endl;
        out << "    Q_OBJECT" << endl;
        out << endl;
        out << "public:" << endl;
        out << "    explicit QQmlAndroid" << cls << "(QObject *parent = 0);" << endl;
        out << endl;
        out << "protected:" << endl;
        out << "    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;" << endl;
        out << "};" << endl;
    }

    void writeHeaderCloseGuard(QTextStream &out)
    {
        const QString name = m_doc.value("class").toString().toUpper();
        out << "#endif // QQMLANDROID" << name << "_P_H" << endl;
    }

    void writeSourceIncludes(QTextStream &out)
    {
        const QString cls = m_doc.value("class").toString().toLower();
        out << "#include \"qqmlandroid" << cls << "_p.h\"" << endl;
    }

    void writeClassImplementation(QTextStream &out)
    {
        const QString cls = m_doc.value("class").toString();
        const QString base = m_doc.value("base").toString();
        const QString pkg = m_doc.value("package").toString();

        out << "QQmlAndroid" << cls << "::QQmlAndroid" << cls << "(QObject *parent) :" << endl;
        out << "    QQmlAndroid" << base << "(parent)" << endl;
        out << "{" << endl;
        out << "}" << endl;

        out << endl;

        out << "QAndroidJniObject QQmlAndroid" << cls << "::onCreate()" << endl;
        out << "{" << endl;
        out << "    return QAndroidJniObject(\"" << pkg << "/" << cls << "\");" << endl;
        out << "}" << endl;
    }

    void writeBeginNamespace(QTextStream &out)
    {
        out << "QT_BEGIN_NAMESPACE" << endl;
    }

    void writeEndNamespace(QTextStream &out)
    {
        out << "QT_END_NAMESPACE" << endl;
    }

    QString m_error;
    QJsonObject m_doc;
};

static void usage(bool showHelp = false)
{
    std::cerr << "Usage: qac [options]" << std::endl;

    if (showHelp) {
        std::cerr << " Generates C++ from a JSON description file" << std::endl
                  << " The options are:" << std::endl
                  << "  -o<file>                 write output to file" << std::endl
                  << "  -h                       display this output" << std::endl;
    }
}

int runQac(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const QStringList args = app.arguments();

    QString inputFileName;
    QString outputFileName;

    int index = 1;
    while (index < args.count()) {
        const QString arg = args.at(index++);
        const QString next = index < args.size() ? args.at(index) : QString();

        if (arg == QLatin1String("-h") || arg == QLatin1String("--help")) {
            usage(/*showHelp*/ true);
            return EXIT_SUCCESS;
        } else if (arg == QLatin1String("-o")) {
            if (next.isEmpty()) {
                std::cerr << "qac: argument to '-o' is missing" << std::endl;
                return EXIT_FAILURE;
            } else {
                outputFileName = next;
                ++index; // consume the next argument
            }
        } else if (arg.startsWith(QLatin1String("-o"))) {
            outputFileName = arg.mid(2);

            if (outputFileName.isEmpty()) {
                std::cerr << "qac: argument to '-o' is missing" << std::endl;
                return EXIT_FAILURE;
            }
        } else {
            const bool isInvalidOpt = arg.startsWith(QLatin1Char('-'));
            if (!isInvalidOpt && inputFileName.isEmpty())
                inputFileName = arg;
            else {
                usage(/*show help*/ isInvalidOpt);
                if (isInvalidOpt)
                    std::cerr << "qac: invalid option '" << qPrintable(arg) << "'" << std::endl;
                else
                    std::cerr << "qac: too many input files specified" << std::endl;
                return EXIT_FAILURE;
            }
        }
    }

    if (inputFileName.isEmpty()) {
        usage();
        return EXIT_SUCCESS;
    }

    QFile inputFile(inputFileName);
    if (!inputFile.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "qac: cannot read '" << qPrintable(inputFileName) << "'"
                  << " (" << qPrintable(inputFile.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    QJsonParseError jsonError;
    const QJsonDocument doc = QJsonDocument::fromJson(inputFile.readAll(), &jsonError);
    inputFile.close();

    if (jsonError.error != QJsonParseError::NoError) {
        std::cerr << "qac: cannot parse '" << qPrintable(inputFileName) << "'"
                  << " (" << qPrintable(jsonError.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    QAC qac(doc);
    if (outputFileName.isEmpty()) {
        QTextStream out(stdout);
        qac.writeHeader(out);
        out << endl;
        qac.writeSource(out);
    } else {
        QFile outputFile(outputFileName);
        if (!outputFile.open(QFile::WriteOnly | QFile::Text)) {
            std::cerr << "qac: cannot write '" << qPrintable(outputFileName) << "'"
                      << " (" << qPrintable(outputFile.errorString()) << ")" << std::endl;
            return EXIT_FAILURE;
        }
        QTextStream out(&outputFile);
        if (outputFileName.endsWith(".h"))
            qac.writeHeader(out);
        else
            qac.writeSource(out);
    }

    return EXIT_SUCCESS;
}

QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    return QT_PREPEND_NAMESPACE(runQac(argc, argv));
}
