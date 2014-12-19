#include "qtqmlandroidanimationmodule_p.h"

#include "qtqmlandroidacceleratedecelerateinterpolator_p.h"
#include "qtqmlandroidaccelerateinterpolator_p.h"
#include "qtqmlandroidalphaanimation_p.h"
#include "qtqmlandroidanimation_p.h"
#include "qtqmlandroidanimationset_p.h"
#include "qtqmlandroidanticipateinterpolator_p.h"
#include "qtqmlandroidanticipateovershootinterpolator_p.h"
#include "qtqmlandroidbounceinterpolator_p.h"
#include "qtqmlandroidcycleinterpolator_p.h"
#include "qtqmlandroiddecelerateinterpolator_p.h"
#include "qtqmlandroidlinearinterpolator_p.h"
#include "qtqmlandroidovershootinterpolator_p.h"
#include "qtqmlandroidpathinterpolator_p.h"
#include "qtqmlandroidrotateanimation_p.h"
#include "qtqmlandroidscaleanimation_p.h"
#include "qtqmlandroidtranslateanimation_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAnimationModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidAccelerateDecelerateInterpolator>(uri, 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QQmlAndroidAccelerateInterpolator>(uri, 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QQmlAndroidAlphaAnimation>(uri, 0, 21, "AlphaAnimation");
    qmlRegisterType<QQmlAndroidAnimation>(uri, 0, 21, "Animation");
    qmlRegisterType<QQmlAndroidAnimationSet>(uri, 0, 21, "AnimationSet");
    qmlRegisterType<QQmlAndroidAnticipateInterpolator>(uri, 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QQmlAndroidAnticipateOvershootInterpolator>(uri, 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QQmlAndroidBounceInterpolator>(uri, 0, 21, "BounceInterpolator");
    qmlRegisterType<QQmlAndroidCycleInterpolator>(uri, 0, 21, "CycleInterpolator");
    qmlRegisterType<QQmlAndroidDecelerateInterpolator>(uri, 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QQmlAndroidInterpolator>(uri, 0, 21, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QQmlAndroidLinearInterpolator>(uri, 0, 21, "LinearInterpolator");
    qmlRegisterType<QQmlAndroidOvershootInterpolator>(uri, 0, 21, "OvershootInterpolator");
    qmlRegisterType<QQmlAndroidPathInterpolator>(uri, 0, 21, "PathInterpolator");
    qmlRegisterType<QQmlAndroidRotateAnimation>(uri, 0, 21, "RotateAnimation");
    qmlRegisterType<QQmlAndroidScaleAnimation>(uri, 0, 21, "ScaleAnimation");
    qmlRegisterType<QQmlAndroidTranslateAnimation>(uri, 0, 21, "TranslateAnimation");
}

}

QT_END_NAMESPACE
