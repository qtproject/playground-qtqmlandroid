#include "qtandroidviewmodule_p.h"

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

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerViewModule(const char *uri)
{
    qmlRegisterUncreatableType<QtAndroidGravity>(uri, 0, 21, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>(uri, 0, 21, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>(uri, 0, 21, "Menu");
    qmlRegisterType<QtAndroidMenuItem>(uri, 0, 21, "MenuItem");
    qmlRegisterType<QtAndroidView>(uri, 0, 21, "View");
    qmlRegisterType<QtAndroidViewGroup>(uri, 0, 21, "ViewGroup");
    qmlRegisterType<QtAndroidWindow>();
}

void registerAnimationModule(const char *uri)
{
    qmlRegisterType<QtAndroidAccelerateDecelerateInterpolator>(uri, 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QtAndroidAccelerateInterpolator>(uri, 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QtAndroidAlphaAnimation>(uri, 0, 21, "AlphaAnimation");
    qmlRegisterType<QtAndroidAnimation>(uri, 0, 21, "Animation");
    qmlRegisterType<QtAndroidAnimationSet>(uri, 0, 21, "AnimationSet");
    qmlRegisterType<QtAndroidAnticipateInterpolator>(uri, 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QtAndroidAnticipateOvershootInterpolator>(uri, 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QtAndroidBounceInterpolator>(uri, 0, 21, "BounceInterpolator");
    qmlRegisterType<QtAndroidCycleInterpolator>(uri, 0, 21, "CycleInterpolator");
    qmlRegisterType<QtAndroidDecelerateInterpolator>(uri, 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QtAndroidInterpolator>("android.view", 0, 21, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QtAndroidLinearInterpolator>(uri, 0, 21, "LinearInterpolator");
    qmlRegisterType<QtAndroidOvershootInterpolator>(uri, 0, 21, "OvershootInterpolator");
    qmlRegisterType<QtAndroidPathInterpolator>(uri, 0, 21, "PathInterpolator");
    qmlRegisterType<QtAndroidRotateAnimation>(uri, 0, 21, "RotateAnimation");
    qmlRegisterType<QtAndroidScaleAnimation>(uri, 0, 21, "ScaleAnimation");
    qmlRegisterType<QtAndroidTranslateAnimation>(uri, 0, 21, "TranslateAnimation");
}

}

QT_END_NAMESPACE
