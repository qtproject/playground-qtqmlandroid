#ifndef QTQMLANDROIDFUNCTIONS_P_H
#define QTQMLANDROIDFUNCTIONS_P_H

#include <functional>
#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

class QString;
class QAndroidJniObject;

namespace QtQmlAndroid
{
    void callFunction(std::function<void()> method);
    void callTextMethod(const QAndroidJniObject &obj, const char *method, const QString &text);
    void callRealMethod(const QAndroidJniObject &obj, const char *method, qreal value);
    void callIntMethod(const QAndroidJniObject &obj, const char *method, int value);
    void callBoolMethod(const QAndroidJniObject &obj, const char *method, bool value);
    void callVoidMethod(const QAndroidJniObject &obj, const char *method);
}

QT_END_NAMESPACE

#endif // QTQMLANDROIDFUNCTIONS_P_H
