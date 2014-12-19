#include <QtQml/qqmlextensionplugin.h>
#include <QtQmlAndroid/private/qtqmlandroidsupportmodule_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidSupportV7AppPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri)
    {
        QtQmlAndroid::registerSupportV7AppModule(uri);
    }
};

QT_END_NAMESPACE

#include "qtqmlandroidsupportv7appplugin.moc"
