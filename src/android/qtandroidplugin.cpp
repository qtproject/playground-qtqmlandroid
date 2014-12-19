#include <QtQml/qqmlextensionplugin.h>

#include "qtandroidmodule_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri)
    {
        Q_UNUSED(uri);
        QtAndroid::registerModule();
    }

    // void initializeEngine(QQmlEngine *engine, const char *uri);
};

QT_END_NAMESPACE
