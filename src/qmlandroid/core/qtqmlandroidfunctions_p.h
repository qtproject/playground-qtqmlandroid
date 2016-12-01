#ifndef QTQMLANDROIDFUNCTIONS_P_H
#define QTQMLANDROIDFUNCTIONS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

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
