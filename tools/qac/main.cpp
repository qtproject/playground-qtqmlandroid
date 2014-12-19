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

    QString errorString() const { return m_error; }

    bool writeHeader(const QString &filePath)
    {
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            m_error = file.errorString();
            return false;
        }

        QTextStream out(&file);
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
        return true;
    }

    bool writeSource(const QString &filePath)
    {
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            m_error = file.errorString();
            return false;
        }

        QTextStream out(&file);
        writeSourceIncludes(out);
        out << endl;
        writeBeginNamespace(out);
        out << endl;
        writeClassImplementation(out);
        out << endl;
        writeEndNamespace(out);
        return true;
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
        const QString cls = m_doc.value("class").toString();
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
                  << "  -o<dir>                 write output to dir" << std::endl
                  << "  -h                      display this output" << std::endl;
    }
}

int runQac(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const QStringList args = app.arguments();

    QString fileName;
    QString outputPath;

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
                outputPath = next;
                ++index; // consume the next argument
            }
        } else if (arg.startsWith(QLatin1String("-o"))) {
            outputPath = arg.mid(2);

            if (outputPath.isEmpty()) {
                std::cerr << "qac: argument to '-o' is missing" << std::endl;
                return EXIT_FAILURE;
            }
        } else {
            const bool isInvalidOpt = arg.startsWith(QLatin1Char('-'));
            if (!isInvalidOpt && fileName.isEmpty())
                fileName = arg;
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

    if (fileName.isEmpty()) {
        usage();
        return EXIT_SUCCESS;
    }

    QFile inputFile(fileName);
    if (!inputFile.open(QFile::ReadOnly)) {
        std::cerr << "qac: cannot read '" << qPrintable(fileName) << "'"
                  << " (" << qPrintable(inputFile.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    QJsonParseError jsonError;
    const QJsonDocument doc = QJsonDocument::fromJson(inputFile.readAll(), &jsonError);
    inputFile.close();

    if (jsonError.error != QJsonParseError::NoError) {
        std::cerr << "qac: cannot parse '" << qPrintable(fileName) << "'"
                  << " (" << qPrintable(jsonError.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    QDir outputDir(outputPath);
    if (outputPath.isEmpty())
        outputDir = QDir::current();

    QString baseName = QFileInfo(inputFile).baseName();
    QString headerFileName = "qac_" + baseName + ".h";
    QString sourceFileName = "qac_" + baseName + ".cpp";

    QAC qac(doc);
    if (!qac.writeHeader(outputDir.filePath(headerFileName))) {
        std::cerr << "qac: cannot write '" << qPrintable(headerFileName) << "'"
                  << " (" << qPrintable(qac.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }
    if (!qac.writeSource(outputDir.filePath(sourceFileName))) {
        std::cerr << "qac: cannot write '" << qPrintable(sourceFileName) << "'"
                  << " (" << qPrintable(qac.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    return QT_PREPEND_NAMESPACE(runQac(argc, argv));
}
