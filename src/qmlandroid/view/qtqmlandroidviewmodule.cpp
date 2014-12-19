#include "qtqmlandroidviewmodule_p.h"

#include "qtqmlandroidgravity_p.h"
#include "qtqmlandroidlayoutparams_p.h"
#include "qtqmlandroidmenu_p.h"
#include "qtqmlandroidmenuitem_p.h"
#include "qtqmlandroidview_p.h"
#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidwindow_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerViewModule(const char *uri)
{
    qmlRegisterUncreatableType<QQmlAndroidGravity>(uri, 0, 21, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QQmlAndroidLayoutParams>(uri, 0, 21, "Layout", "Layout is an attached property");
    qmlRegisterType<QQmlAndroidMenu>(uri, 0, 21, "Menu");
    qmlRegisterType<QQmlAndroidMenuItem>(uri, 0, 21, "MenuItem");
    qmlRegisterType<QQmlAndroidView>(uri, 0, 21, "View");
    qmlRegisterType<QQmlAndroidViewGroup>(uri, 0, 21, "ViewGroup");
    qmlRegisterType<QQmlAndroidWindow>();
}

}

QT_END_NAMESPACE
