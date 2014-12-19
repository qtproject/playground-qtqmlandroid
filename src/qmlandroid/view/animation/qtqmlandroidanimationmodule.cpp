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
    qmlRegisterType<QtQmlAndroidAccelerateDecelerateInterpolator>(uri, 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QtQmlAndroidAccelerateInterpolator>(uri, 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QtQmlAndroidAlphaAnimation>(uri, 0, 21, "AlphaAnimation");
    qmlRegisterType<QtQmlAndroidAnimation>(uri, 0, 21, "Animation");
    qmlRegisterType<QtQmlAndroidAnimationSet>(uri, 0, 21, "AnimationSet");
    qmlRegisterType<QtQmlAndroidAnticipateInterpolator>(uri, 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QtQmlAndroidAnticipateOvershootInterpolator>(uri, 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QtQmlAndroidBounceInterpolator>(uri, 0, 21, "BounceInterpolator");
    qmlRegisterType<QtQmlAndroidCycleInterpolator>(uri, 0, 21, "CycleInterpolator");
    qmlRegisterType<QtQmlAndroidDecelerateInterpolator>(uri, 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QtQmlAndroidInterpolator>(uri, 0, 21, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QtQmlAndroidLinearInterpolator>(uri, 0, 21, "LinearInterpolator");
    qmlRegisterType<QtQmlAndroidOvershootInterpolator>(uri, 0, 21, "OvershootInterpolator");
    qmlRegisterType<QtQmlAndroidPathInterpolator>(uri, 0, 21, "PathInterpolator");
    qmlRegisterType<QtQmlAndroidRotateAnimation>(uri, 0, 21, "RotateAnimation");
    qmlRegisterType<QtQmlAndroidScaleAnimation>(uri, 0, 21, "ScaleAnimation");
    qmlRegisterType<QtQmlAndroidTranslateAnimation>(uri, 0, 21, "TranslateAnimation");
}

}

QT_END_NAMESPACE
