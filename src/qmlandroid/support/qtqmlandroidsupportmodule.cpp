#include "qtqmlandroidsupportmodule_p.h"

#include "qtqmlandroiddrawerlayout_p.h"
#include "qtqmlandroidswiperefreshlayout_p.h"

#include "qtqmlandroidactionbardrawertoggle_p.h"

#include "qtqmlandroidcardview_p.h"
#include "qtqmlandroidrecycleradapter_p.h"
#include "qtqmlandroidrecyclerview_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerSupportV4WidgetModule(const char *uri)
{
    qmlRegisterType<QtQmlAndroidDrawerLayout>(uri, 0, 21, "DrawerLayout");
    qmlRegisterType<QtQmlAndroidSwipeRefreshLayout>(uri, 0, 21, "SwipeRefreshLayout");
}

void registerSupportV7AppModule(const char *uri)
{
    qmlRegisterType<QtQmlAndroidActionBarDrawerToggle>(uri, 0, 21, "ActionBarDrawerToggle");
}

void registerSupportV7WidgetModule(const char *uri)
{
    qmlRegisterType<QtQmlAndroidCardView>(uri, 0, 21, "CardView");
    qmlRegisterType<QtQmlAndroidRecyclerAdapter>(uri, 0, 21, "RecyclerAdapter");
    qmlRegisterType<QtQmlAndroidRecyclerView>(uri, 0, 21, "RecyclerView");
}

}

QT_END_NAMESPACE
