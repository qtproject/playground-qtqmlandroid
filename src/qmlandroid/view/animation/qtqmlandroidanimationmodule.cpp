#include "qtqmlandroidanimationmodule_p.h"

#include "qqmlandroidacceleratedecelerateinterpolator_p.h"
#include "qqmlandroidaccelerateinterpolator_p.h"
#include "qqmlandroidalphaanimation_p.h"
#include "qqmlandroidanimation_p.h"
#include "qqmlandroidanimationset_p.h"
#include "qqmlandroidanticipateinterpolator_p.h"
#include "qqmlandroidanticipateovershootinterpolator_p.h"
#include "qqmlandroidbounceinterpolator_p.h"
#include "qqmlandroidcycleinterpolator_p.h"
#include "qqmlandroiddecelerateinterpolator_p.h"
#include "qqmlandroidlinearinterpolator_p.h"
#include "qqmlandroidovershootinterpolator_p.h"
#include "qqmlandroidpathinterpolator_p.h"
#include "qqmlandroidrotateanimation_p.h"
#include "qqmlandroidscaleanimation_p.h"
#include "qqmlandroidtranslateanimation_p.h"

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
