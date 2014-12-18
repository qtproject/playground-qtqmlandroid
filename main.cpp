#include <QtQml>

#include "qtandroidmodule_p.h"

#include "qtandroiddrawerlayout_p.h"
#include "qtandroidswiperefreshlayout_p.h"

#include "qtandroidactionbardrawertoggle_p.h"
#include "qtandroidcardview_p.h"
#include "qtandroidrecycleradapter_p.h"
#include "qtandroidrecyclerview_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qRegisterMetaType<QQmlPropertyMap *>();

    QtAndroid::registerModule();

    qmlRegisterType<QtAndroidDrawerLayout>("android.support.v4.widget", 0, 21, "DrawerLayout");
    qmlRegisterType<QtAndroidSwipeRefreshLayout>("android.support.v4.widget", 0, 21, "SwipeRefreshLayout");

    qmlRegisterType<QtAndroidActionBarDrawerToggle>("android.support.v7.app", 0, 21, "ActionBarDrawerToggle");
    qmlRegisterType<QtAndroidCardView>("android.support.v7.widget", 0, 21, "CardView");
    qmlRegisterType<QtAndroidRecyclerAdapter>("android.support.v7.widget", 0, 21, "RecyclerAdapter");
    qmlRegisterType<QtAndroidRecyclerView>("android.support.v7.widget", 0, 21, "RecyclerView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
