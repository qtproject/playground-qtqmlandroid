#include <QtCore/qcoreapplication.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qfile.h>
#include <iostream>
#include <cstdlib>

QT_BEGIN_NAMESPACE

static void usage(bool showHelp = false)
{
    std::cerr << "Usage: qac [options] file" << std::endl;

    if (showHelp) {
        std::cerr << " Generates C++ from a JSON description file" << std::endl
                  << " The options are:" << std::endl
                  << "  -o<file>                write output to file rather than stdout" << std::endl
                  << "  -h                      display this output" << std::endl;
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
    if (!inputFile.open(QFile::ReadOnly)) {
        std::cerr << "qac: '" << qPrintable(inputFileName) << "' no such file or directory" << std::endl;
        return EXIT_FAILURE;
    }

    QJsonParseError error;
    const QJsonDocument doc = QJsonDocument::fromJson(inputFile.readAll(), &error);
    inputFile.close();

    if (error.error != QJsonParseError::NoError) {
        std::cerr << "qac: cannot parse '" << qPrintable(inputFileName) << "' (" << qPrintable(error.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    if (outputFileName.isEmpty()) {
        const QByteArray output = doc.toJson();
        std::cout << output.constData();
    } else {
        QFile outputFile(outputFileName);
        if (!outputFile.open(QFile::WriteOnly)) {
            std::cerr << "qac: cannot write '" << qPrintable(outputFileName) << "' (permission denied)" << std::endl;
            return EXIT_FAILURE;
        }

        outputFile.write(doc.toJson());
        outputFile.close();
    }

    return EXIT_SUCCESS;
}

QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    return QT_PREPEND_NAMESPACE(runQac(argc, argv));
}
