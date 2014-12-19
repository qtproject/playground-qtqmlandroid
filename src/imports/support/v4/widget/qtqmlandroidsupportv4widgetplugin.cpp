#include <QtQml/qqmlextensionplugin.h>
#include <QtQmlAndroid/private/qtqmlandroidsupportmodule_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidSupportV4WidgetPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri)
    {
        QtQmlAndroid::registerSupportV4WidgetModule(uri);
    }
};

QT_END_NAMESPACE

#include "qtqmlandroidsupportv4widgetplugin.moc"
