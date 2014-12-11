#include "qtdroidfunctions_p.h"
#include <QtCore/qstring.h>
#include <QtCore/private/qjnihelpers_p.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

namespace QtAndroid {

void callFunction(std::function<void()> method)
{
    QAndroidJniEnvironment env;
    QRunnable *runnable = new QtConcurrent::StoredFunctorCall0<void, decltype(method)>(method);
    QtAndroidPrivate::runOnUiThread(runnable, env);
}

void callTextMethod(const QAndroidJniObject &obj, const char *method, const QString &text)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(text).object());
        });
    }
}

void callRealMethod(const QAndroidJniObject &obj, const char *method, qreal value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(F)V", value);
        });
    }
}

void callIntMethod(const QAndroidJniObject &obj, const char *method, int value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(I)V", value);
        });
    }
}

void callBoolMethod(const QAndroidJniObject &obj, const char *method, bool value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Z)V", value);
        });
    }
}

void callVoidMethod(const QAndroidJniObject &obj, const char *method)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method);
        });
    }
}

}
