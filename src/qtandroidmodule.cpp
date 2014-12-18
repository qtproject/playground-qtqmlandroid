#include "qtandroidmodule_p.h"

#include "qtandroidr_p.h"

#include "qtandroidappmodule_p.h"
#include "qtandroidcontentmodule_p.h"
#include "qtandroidgraphicsmodule_p.h"
#include "qtandroidsupportmodule_p.h"
#include "qtandroidviewmodule_p.h"
#include "qtandroidwidgetmodule_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerModule()
{
    qmlRegisterSingletonType<QtAndroidR>("android", 0, 21, "R", QtAndroidR::provider);

    QtAndroid::registerAppModule("android.app");
    QtAndroid::registerContentModule("android.content");
    QtAndroid::registerGraphicsModule("android.graphics");
    QtAndroid::registerDrawableModule("android.graphics.drawable");
    QtAndroid::registerSupportV4WidgetModule("android.support.v4.widget");
    QtAndroid::registerSupportV7AppModule("android.support.v7.app");
    QtAndroid::registerSupportV7WidgetModule("android.support.v7.widget");
    QtAndroid::registerViewModule("android.view");
    QtAndroid::registerAnimationModule("android.view.animation");
    QtAndroid::registerWidgetModule("android.widget");
}

}

QT_END_NAMESPACE
