#ifndef QTANDROIDFUNCTIONS_P_H
#define QTANDROIDFUNCTIONS_P_H

#include <functional>
#include <Qtcore/qglobal.h>

QT_BEGIN_NAMESPACE

class QString;
class QAndroidJniObject;

namespace QtAndroid
{
    void callFunction(std::function<void()> method);
    void callTextMethod(const QAndroidJniObject &obj, const char *method, const QString &text);
    void callRealMethod(const QAndroidJniObject &obj, const char *method, qreal value);
    void callIntMethod(const QAndroidJniObject &obj, const char *method, int value);
    void callBoolMethod(const QAndroidJniObject &obj, const char *method, bool value);
    void callVoidMethod(const QAndroidJniObject &obj, const char *method);
}

QT_END_NAMESPACE

#endif // QTANDROIDFUNCTIONS_P_H
