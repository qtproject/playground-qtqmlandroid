#ifndef QQMLANDROIDNUMBERPICKER_P_H
#define QQMLANDROIDNUMBERPICKER_P_H

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

#include "qqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidNumberPicker : public QQmlAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit QQmlAndroidNumberPicker(QQmlAndroidView *parent = 0);

    int value() const;
    void setValue(int value);

Q_SIGNALS:
    void valueChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onValueChange(JNIEnv *env, jobject object, jlong instance, jint value);

private Q_SLOTS:
    bool updateValue(int value);

private:
    int m_value;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDNUMBERPICKER_P_H
