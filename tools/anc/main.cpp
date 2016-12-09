/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/qcoreapplication.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qtextstream.h>
#include <QtCore/qjsonvalue.h>
#include <QtCore/qjsonarray.h>
#include <QtCore/qdebug.h>
#include <QtCore/qfile.h>
#include <QtCore/qdir.h>
#include <iostream>
#include <cstdlib>

QT_BEGIN_NAMESPACE

class Anc
{
public:
    Anc(const QJsonDocument &doc) : m_doc(doc.object()) { }

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
        out << "#include \"qqmlandroidoptional_p.h\"" << endl;
        out << "#include \"qqmlandroid" << base << "_p.h\"" << endl;
        out << "#include <QtAndroidExtras/qandroidjniobject.h>" << endl;
    }

    void writeClassDeclaration(QTextStream &out)
    {
        const QString cls = m_doc.value("class").toString();
        const QString base = m_doc.value("base").toString();
        const QJsonArray properties = m_doc.value("properties").toArray();
        out << "class QQmlAndroid" << cls << " : public QQmlAndroid" << base << endl;
        out << "{" << endl;
        out << "    Q_OBJECT" << endl;
        writePropertyMacros(out, properties);
        out << endl;
        out << "public:" << endl;
        out << "    explicit QQmlAndroid" << cls << "(QObject *parent = 0);" << endl;
        out << endl;
        writePropertyDeclarations(out, properties);
        out << "Q_SIGNALS:" << endl;
        writePropertyNotifiers(out, properties);
        out << endl;
        out << "protected:" << endl;
        out << "    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;" << endl;
        out << endl;
        out << "private:" << endl;
        writePropertyMembers(out, properties);
        out << "};" << endl;
    }

    void writePropertyMacros(QTextStream &out, const QJsonArray &properties)
    {
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            const QString name = property.value("name").toString();
            const QString type = property.value("type").toString();
            out << "    Q_PROPERTY(" << type << " " << name << " READ " << name << " WRITE set" << capitalize(name) << " NOTIFY " << name << "Changed)" << endl;
        }
    }

    void writePropertyDeclarations(QTextStream &out, const QJsonArray &properties)
    {
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            const QString name = property.value("name").toString();
            const QString type = property.value("type").toString();
            out << "    " << type << " " << name << "() const;" << endl;
            out << "    void set" << capitalize(name) << "(";
            if (isPrimitive(type))
                out << type << " " << name << ");";
            else
                out << "const " << type << " &" << name << ");";
            out << endl << endl;
        }
    }

    void writePropertyNotifiers(QTextStream &out, const QJsonArray &properties)
    {
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            const QString name = property.value("name").toString();
            out << "    void " << name << "Changed();" << endl;
        }
    }

    void writePropertyMembers(QTextStream &out, const QJsonArray &properties)
    {
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            const QString name = property.value("name").toString();
            const QString type = property.value("type").toString();
            const bool optional = property.value("optional").toBool();
            if (optional)
                out << "    QQmlAndroidOptional<" << type << "> m_" << name << ";" << endl;
            else
                out << "    " << type << " m_" << name << ";" << endl;
        }
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
        const QJsonArray properties = m_doc.value("properties").toArray();

        out << "QQmlAndroid" << cls << "::QQmlAndroid" << cls << "(QObject *parent) :" << endl;
        out << "    QQmlAndroid" << base << "(parent)" << endl;
        out << "{" << endl;
        out << "}" << endl;
        out << endl;
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            writePropertyGetter(out, property);
            out << endl;
            writePropertySetter(out, property);
            out << endl;
        }
        const QJsonObject jni = m_doc.value("jni").toObject();
        const QJsonObject construction = jni.value("construction").toObject();
        writeJniConstruction(out, construction);
        const QJsonObject inflation = jni.value("inflation").toObject();
        if (!inflation.isEmpty())
            writeJniInflation(out, inflation);
    }

    QJsonObject findProperty(const QString &name)
    {
        const QJsonArray properties = m_doc.value("properties").toArray();
        foreach (const QJsonValue &value, properties) {
            const QJsonObject property = value.toObject();
            if (name == property.value("name").toString())
                return property;
        }
        return QJsonObject();
    }

    QString jniType(const QString &type)
    {
        if (type == "bool")
            return "Z";
        if (type == "int")
            return "I";
        if (type == "qreal" || type == "float")
            return "F";
        if (type == "double")
            return "D";
        if (type == "long")
            return "J";
        return QString();
    }

    void writeJniConstruction(QTextStream &out, const QJsonObject &construction)
    {
        const QString cls = m_doc.value("class").toString();
        const QString pkg = m_doc.value("package").toString();

        out << "QAndroidJniObject QQmlAndroid" << cls << "::onCreate()" << endl;
        out << "{" << endl;
        const QJsonArray constructors = construction.value("constructors").toArray();
        if (!constructors.isEmpty()) {
            foreach (const QJsonValue &c, constructors) {
                const QJsonArray arguments = c.toObject().value("arguments").toArray();
                QStringList types, fields, conditions;
                foreach (const QJsonValue &a, arguments) {
                    const QJsonObject property = findProperty(a.toString());
                    const QString name = property.value("name").toString();
                    const QString type = property.value("type").toString();
                    const bool optional = property.value("optional").toBool();
                    if (optional)
                        conditions += "!m_" + name + ".isNull()";
                    types += jniType(type);
                    fields += "m_" + name + (optional ? "" : "");
                }
                if (!conditions.isEmpty())
                    out << "    if (" << conditions.join(" && ") << ")" << endl << "    ";
                out << "    return QAndroidJniObject(\"" << pkg << "/" << cls << "\"";
                if (!types.isEmpty())
                    out << ", \"(" << types.join("") << ")V\"";
                if (!fields.isEmpty())
                    out << ", " << fields.join(", ");
                out << ");" << endl;
            }
        } else {
            out << "    return QAndroidJniObject(\"" << pkg << "/" << cls << "\");" << endl;
        }
        out << "}" << endl;
    }

    void writeJniInflation(QTextStream &out, const QJsonObject &inflation)
    {
        Q_UNUSED(out);
        Q_UNUSED(inflation);
#if 0
        const QString cls = m_doc.value("class").toString();
        const QString base = m_doc.value("base").toString();

        out << "QAndroidJniObject QQmlAndroid" << cls << "::onInflate(QAndroidJniObject &instance)" << endl;
        out << "{" << endl;
        out << "    QQmlAndroid" << base << "::onInflate(instance);" << endl;
        out << "}" << endl;
#endif
    }

    void writeValue(QTextStream &out, const QJsonValue &value)
    {
        switch (value.type()) {
        case QJsonValue::Bool:
            out << value.toBool();
            break;
        case QJsonValue::Double:
            out << value.toDouble();
            break;
        default:
            out << value.toVariant().toString();
            break;
        }
    }

    void writePropertyGetter(QTextStream &out, const QJsonObject &property)
    {
        const QString cls = m_doc.value("class").toString();
        const QString name = property.value("name").toString();
        const QString type = property.value("type").toVariant().toString();
        const bool optional = property.value("optional").toBool();

        out << type << " QQmlAndroid" << cls << "::" << name << "() const" << endl;
        out << "{" << endl;
        if (optional) {
            out << "    if (m_" << name << ".isNull())" << endl;
            out << "        return ";
            writeValue(out, property.value("value"));
            out << ";" << endl;
        }
        out << "    return m_" << name << ";" << endl;
        out << "}" << endl;
    }

    void writePropertySetter(QTextStream &out, const QJsonObject &property)
    {
        const QString cls = m_doc.value("class").toString();
        const QString name = property.value("name").toString();
        const QString type = property.value("type").toVariant().toString();
        const bool optional = property.value("optional").toBool();

        out << "void QQmlAndroid" << cls << "::set" << capitalize(name) << "(";
        if (isPrimitive(type))
            out << type << " " << name << ")" << endl;
        else
            out << optionalize(type) << " " << name << ")" << endl;
        out << "{" << endl;
        if (optional)
            out << "    if (m_" << name << ".isNull() || m_" << name << " != " << name << ") {" << endl;
        else
            out << "    if (m_" << name << " != " << name << ") {" << endl;
        out << "        m_" << name << " = " << name << ";" << endl;
        out << "        emit " << name << "Changed();" << endl;
        out << "    }" << endl;
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

    static QString capitalize(const QString &str)
    {
        return str.left(1).toUpper() + str.mid(1);
    }

    static QString optionalize(const QString &type)
    {
        return "QQmlAndroidOptional<" + type + ">";
    }

    static bool isPrimitive(const QString &type)
    {
        return type.at(0).isLower();
    }

    QString m_error;
    QJsonObject m_doc;
};

static void usage(bool showHelp = false)
{
    std::cerr << "Usage: anc [options]" << std::endl;

    if (showHelp) {
        std::cerr << " Generates C++ from a JSON description file" << std::endl
                  << " The options are:" << std::endl
                  << "  -o<file>                 write output to file" << std::endl
                  << "  -h                       display this output" << std::endl;
    }
}

int runAnc(int argc, char *argv[])
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
                std::cerr << "anc: argument to '-o' is missing" << std::endl;
                return EXIT_FAILURE;
            } else {
                outputFileName = next;
                ++index; // consume the next argument
            }
        } else if (arg.startsWith(QLatin1String("-o"))) {
            outputFileName = arg.mid(2);

            if (outputFileName.isEmpty()) {
                std::cerr << "anc: argument to '-o' is missing" << std::endl;
                return EXIT_FAILURE;
            }
        } else {
            const bool isInvalidOpt = arg.startsWith(QLatin1Char('-'));
            if (!isInvalidOpt && inputFileName.isEmpty())
                inputFileName = arg;
            else {
                usage(/*show help*/ isInvalidOpt);
                if (isInvalidOpt)
                    std::cerr << "anc: invalid option '" << qPrintable(arg) << "'" << std::endl;
                else
                    std::cerr << "anc: too many input files specified" << std::endl;
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
        std::cerr << "anc: cannot read '" << qPrintable(inputFileName) << "'"
                  << " (" << qPrintable(inputFile.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    QJsonParseError jsonError;
    const QJsonDocument doc = QJsonDocument::fromJson(inputFile.readAll(), &jsonError);
    inputFile.close();

    if (jsonError.error != QJsonParseError::NoError) {
        std::cerr << "anc: cannot parse '" << qPrintable(inputFileName) << "'"
                  << " (" << qPrintable(jsonError.errorString()) << ")" << std::endl;
        return EXIT_FAILURE;
    }

    Anc anc(doc);
    if (outputFileName.isEmpty()) {
        QTextStream out(stdout);
        anc.writeHeader(out);
        out << endl;
        anc.writeSource(out);
    } else {
        QFile outputFile(outputFileName);
        if (!outputFile.open(QFile::WriteOnly | QFile::Text)) {
            std::cerr << "anc: cannot write '" << qPrintable(outputFileName) << "'"
                      << " (" << qPrintable(outputFile.errorString()) << ")" << std::endl;
            return EXIT_FAILURE;
        }
        QTextStream out(&outputFile);
        if (outputFileName.endsWith(".h"))
            anc.writeHeader(out);
        else
            anc.writeSource(out);
    }

    return EXIT_SUCCESS;
}

QT_END_NAMESPACE

int main(int argc, char *argv[])
{
    return QT_PREPEND_NAMESPACE(runAnc(argc, argv));
}
