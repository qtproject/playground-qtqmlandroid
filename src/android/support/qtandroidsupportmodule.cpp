#include "qtandroidsupportmodule_p.h"

#include "qtandroiddrawerlayout_p.h"
#include "qtandroidswiperefreshlayout_p.h"

#include "qtandroidactionbardrawertoggle_p.h"

#include "qtandroidcardview_p.h"
#include "qtandroidrecycleradapter_p.h"
#include "qtandroidrecyclerview_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerSupportV4WidgetModule(const char *uri)
{
    qmlRegisterType<QtAndroidDrawerLayout>(uri, 0, 21, "DrawerLayout");
    qmlRegisterType<QtAndroidSwipeRefreshLayout>(uri, 0, 21, "SwipeRefreshLayout");
}

void registerSupportV7AppModule(const char *uri)
{
    qmlRegisterType<QtAndroidActionBarDrawerToggle>(uri, 0, 21, "ActionBarDrawerToggle");
}

void registerSupportV7WidgetModule(const char *uri)
{
    qmlRegisterType<QtAndroidCardView>(uri, 0, 21, "CardView");
    qmlRegisterType<QtAndroidRecyclerAdapter>(uri, 0, 21, "RecyclerAdapter");
    qmlRegisterType<QtAndroidRecyclerView>(uri, 0, 21, "RecyclerView");
}

}

QT_END_NAMESPACE
