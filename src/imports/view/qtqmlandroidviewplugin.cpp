#include <QtQml/qqmlextensionplugin.h>
#include <QtQmlAndroid/private/qtqmlandroidviewmodule_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri)
    {
        QtQmlAndroid::registerViewModule(uri);
    }
};

QT_END_NAMESPACE

#include "qtqmlandroidviewplugin.moc"
