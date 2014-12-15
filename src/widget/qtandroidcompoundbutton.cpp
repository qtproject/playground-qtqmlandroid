#include "qtandroidcompoundbutton_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidCompoundButton::QtAndroidCompoundButton(QtAndroidView *parent) :
    QtAndroidButton(parent), m_checked(false)
{
}

bool QtAndroidCompoundButton::isChecked() const
{
    return m_checked;
}

void QtAndroidCompoundButton::setChecked(bool checked)
{
    if (updateChecked(checked))
        QtAndroid::callBoolMethod(instance(), "setChecked", checked);
}

bool QtAndroidCompoundButton::updateChecked(bool arg)
{
    if (arg != isChecked()) {
        m_checked = arg;
        emit checkedChanged();
        return true;
    }
    return false;
}

void QtAndroidCompoundButton::toggle()
{
    QtAndroid::callVoidMethod(instance(), "toggle");
}

QAndroidJniObject QtAndroidCompoundButton::onCreate()
{
    return QAndroidJniObject("android/widget/CompoundButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCompoundButton::onInflate(QAndroidJniObject &instance)
{
    QtAndroidButton::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtCompoundButtonListener",
                                   "(Landroid/widget/CompoundButton;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setChecked", "(Z)V", m_checked);
}

void QtAndroidCompoundButton::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JZ)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidCompoundButton::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jboolean isChecked)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidCompoundButton *button = reinterpret_cast<QtAndroidCompoundButton *>(instance);
    if (button)
        QMetaObject::invokeMethod(button, "updateChecked", Qt::QueuedConnection, Q_ARG(bool, isChecked));
}
