#include <QtQml/qqmlextensionplugin.h>
#include <QtQmlAndroid/private/qtqmlandroidgraphicsmodule_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidGraphicsPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri)
    {
        QtQmlAndroid::registerGraphicsModule(uri);
    }
};

QT_END_NAMESPACE

#include "qtqmlandroidgraphicsplugin.moc"
