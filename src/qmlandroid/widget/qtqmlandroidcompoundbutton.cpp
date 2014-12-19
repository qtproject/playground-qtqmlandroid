#include "qtqmlandroidcompoundbutton_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidCompoundButton::QtQmlAndroidCompoundButton(QtQmlAndroidView *parent) :
    QtQmlAndroidButton(parent), m_checked(false)
{
}

bool QtQmlAndroidCompoundButton::isChecked() const
{
    return m_checked;
}

void QtQmlAndroidCompoundButton::setChecked(bool checked)
{
    if (updateChecked(checked))
        QtQmlAndroid::callBoolMethod(instance(), "setChecked", checked);
}

bool QtQmlAndroidCompoundButton::updateChecked(bool arg)
{
    if (arg != isChecked()) {
        m_checked = arg;
        emit checkedChanged();
        return true;
    }
    return false;
}

void QtQmlAndroidCompoundButton::toggle()
{
    QtQmlAndroid::callVoidMethod(instance(), "toggle");
}

QAndroidJniObject QtQmlAndroidCompoundButton::onCreate()
{
    return QAndroidJniObject("android/widget/CompoundButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidCompoundButton::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidButton::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtCompoundButtonListener",
                                   "(Landroid/widget/CompoundButton;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setChecked", "(Z)V", m_checked);
}

void QtQmlAndroidCompoundButton::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JZ)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidCompoundButton::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jboolean isChecked)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidCompoundButton *button = reinterpret_cast<QtQmlAndroidCompoundButton *>(instance);
    if (button)
        QMetaObject::invokeMethod(button, "updateChecked", Qt::QueuedConnection, Q_ARG(bool, isChecked));
}

QT_END_NAMESPACE
