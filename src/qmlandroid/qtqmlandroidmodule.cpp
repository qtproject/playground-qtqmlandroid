#include "qtqmlandroidmodule_p.h"

#include "qtqmlandroidr_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAndroidModule(const char *uri)
{
    qmlRegisterSingletonType<QtQmlAndroidR>(uri, 0, 21, "R", QtQmlAndroidR::provider);

//    QtQmlAndroid::registerAppModule("android.app");
//    QtQmlAndroid::registerContentModule("android.content");
//    QtQmlAndroid::registerGraphicsModule("android.graphics");
//    QtQmlAndroid::registerDrawableModule("android.graphics.drawable");
//    QtQmlAndroid::registerSupportV4WidgetModule("android.support.v4.widget");
//    QtQmlAndroid::registerSupportV7AppModule("android.support.v7.app");
//    QtQmlAndroid::registerSupportV7WidgetModule("android.support.v7.widget");
//    QtQmlAndroid::registerViewModule("android.view");
//    QtQmlAndroid::registerAnimationModule("android.view.animation");
//    QtQmlAndroid::registerWidgetModule("android.widget");
}

}

QT_END_NAMESPACE
