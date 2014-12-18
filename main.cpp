#include <QtQml>

#include "qtandroidappmodule_p.h"

#include "qtandroidcontext_p.h"

#include "qtandroidcolor_p.h"
#include "qtandroidcolordrawable_p.h"
#include "qtandroiddrawable_p.h"

#include "qtandroidr_p.h"

#include "qtandroidgravity_p.h"
#include "qtandroidlayoutparams_p.h"
#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"
#include "qtandroidview_p.h"
#include "qtandroidviewgroup_p.h"
#include "qtandroidwindow_p.h"

#include "qtandroidacceleratedecelerateinterpolator_p.h"
#include "qtandroidaccelerateinterpolator_p.h"
#include "qtandroidalphaanimation_p.h"
#include "qtandroidanimation_p.h"
#include "qtandroidanimationset_p.h"
#include "qtandroidanticipateinterpolator_p.h"
#include "qtandroidanticipateovershootinterpolator_p.h"
#include "qtandroidbounceinterpolator_p.h"
#include "qtandroidcycleinterpolator_p.h"
#include "qtandroiddecelerateinterpolator_p.h"
#include "qtandroidlinearinterpolator_p.h"
#include "qtandroidovershootinterpolator_p.h"
#include "qtandroidpathinterpolator_p.h"
#include "qtandroidrotateanimation_p.h"
#include "qtandroidscaleanimation_p.h"
#include "qtandroidtranslateanimation_p.h"

#include "qtandroidwidgetmodule_p.h"

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

    QtAndroid::registerAppModule("android.app");

    qmlRegisterType<QtAndroidContext>();

    qmlRegisterSingletonType<QtAndroidColor>("android.graphics", 0, 21, "Color", QtAndroidColor::provider);
    qmlRegisterType<QtAndroidColorDrawable>("android.graphics.drawable", 0, 21, "ColorDrawable");
    qmlRegisterType<QtAndroidDrawable>("android.graphics.drawable", 0, 21, "Drawable");

    qmlRegisterSingletonType<QtAndroidR>("android.R", 0, 21, "R", QtAndroidR::provider);

    qmlRegisterUncreatableType<QtAndroidGravity>("android.view", 0, 21, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>("android.view", 0, 21, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>("android.view", 0, 21, "Menu");
    qmlRegisterType<QtAndroidMenuItem>("android.view", 0, 21, "MenuItem");
    qmlRegisterType<QtAndroidView>("android.view", 0, 21, "View");
    qmlRegisterType<QtAndroidViewGroup>("android.view", 0, 21, "ViewGroup");
    qmlRegisterType<QtAndroidWindow>();

    qmlRegisterType<QtAndroidAccelerateDecelerateInterpolator>("android.view.animation", 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QtAndroidAccelerateInterpolator>("android.view.animation", 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QtAndroidAlphaAnimation>("android.view.animation", 0, 21, "AlphaAnimation");
    qmlRegisterType<QtAndroidAnimation>("android.view.animation", 0, 21, "Animation");
    qmlRegisterType<QtAndroidAnimationSet>("android.view.animation", 0, 21, "AnimationSet");
    qmlRegisterType<QtAndroidAnticipateInterpolator>("android.view.animation", 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QtAndroidAnticipateOvershootInterpolator>("android.view.animation", 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QtAndroidBounceInterpolator>("android.view.animation", 0, 21, "BounceInterpolator");
    qmlRegisterType<QtAndroidCycleInterpolator>("android.view.animation", 0, 21, "CycleInterpolator");
    qmlRegisterType<QtAndroidDecelerateInterpolator>("android.view.animation", 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QtAndroidInterpolator>("android.view", 0, 21, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QtAndroidLinearInterpolator>("android.view.animation", 0, 21, "LinearInterpolator");
    qmlRegisterType<QtAndroidOvershootInterpolator>("android.view.animation", 0, 21, "OvershootInterpolator");
    qmlRegisterType<QtAndroidPathInterpolator>("android.view.animation", 0, 21, "PathInterpolator");
    qmlRegisterType<QtAndroidRotateAnimation>("android.view.animation", 0, 21, "RotateAnimation");
    qmlRegisterType<QtAndroidScaleAnimation>("android.view.animation", 0, 21, "ScaleAnimation");
    qmlRegisterType<QtAndroidTranslateAnimation>("android.view.animation", 0, 21, "TranslateAnimation");

    QtAndroid::registerWidgetModule("android.widget");

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
