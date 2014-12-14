#ifndef QTANDROIDNUMBERPICKER_P_H
#define QTANDROIDNUMBERPICKER_P_H

#include "qtandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidNumberPicker : public QtAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit QtAndroidNumberPicker(QtAndroidView *parent = 0);

    int value() const;
    void setValue(int value);

Q_SIGNALS:
    void valueChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onValueChange(JNIEnv *env, jobject object, jlong instance, jint value);

private Q_SLOTS:
    bool updateValue(int value);

private:
    int m_value;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDNUMBERPICKER_P_H
