#include "qtqmlandroidsupportmodule_p.h"

#include "qqmlandroiddrawerlayout_p.h"
#include "qqmlandroidswiperefreshlayout_p.h"

#include "qqmlandroidactionbardrawertoggle_p.h"

#include "qqmlandroidcardview_p.h"
#include "qqmlandroidrecycleradapter_p.h"
#include "qqmlandroidrecyclerview_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerSupportV4WidgetModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidDrawerLayout>(uri, 0, 21, "DrawerLayout");
    qmlRegisterType<QQmlAndroidSwipeRefreshLayout>(uri, 0, 21, "SwipeRefreshLayout");
}

void registerSupportV7AppModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidActionBarDrawerToggle>(uri, 0, 21, "ActionBarDrawerToggle");
}

void registerSupportV7WidgetModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidCardView>(uri, 0, 21, "CardView");
    qmlRegisterType<QQmlAndroidRecyclerAdapter>(uri, 0, 21, "RecyclerAdapter");
    qmlRegisterType<QQmlAndroidRecyclerView>(uri, 0, 21, "RecyclerView");
}

}

QT_END_NAMESPACE
