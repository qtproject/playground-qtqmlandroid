#include <QtQml>

#include "qtandroidmodule_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qRegisterMetaType<QQmlPropertyMap *>();

    QtAndroid::registerModule();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
