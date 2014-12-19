#include "qqmlandroidnumberpicker_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidNumberPicker::QQmlAndroidNumberPicker(QQmlAndroidView *parent) :
    QQmlAndroidLinearLayout(parent), m_value(0)
{
}

int QQmlAndroidNumberPicker::value() const
{
    return m_value;
}

void QQmlAndroidNumberPicker::setValue(int value)
{
    if (updateValue(value))
        QtQmlAndroid::callIntMethod(instance(), "setValue", value);
}

bool QQmlAndroidNumberPicker::updateValue(int value)
{
    if (m_value != value) {
        m_value = value;
        emit valueChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QQmlAndroidNumberPicker::onCreate()
{
    return QAndroidJniObject("android/widget/NumberPicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidNumberPicker::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLinearLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtNumberPickerListener",
                                   "(Landroid/widget/NumberPicker;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setValue", "(I)V", m_value);
}

void QQmlAndroidNumberPicker::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onValueChange", "(JI)V", reinterpret_cast<void *>(onValueChange)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidNumberPicker::onValueChange(JNIEnv *env, jobject object, jlong instance, jint value)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidNumberPicker *picker = reinterpret_cast<QQmlAndroidNumberPicker *>(instance);
    if (picker)
        QMetaObject::invokeMethod(picker, "updateValue", Qt::QueuedConnection, Q_ARG(int, value));
}

QT_END_NAMESPACE
