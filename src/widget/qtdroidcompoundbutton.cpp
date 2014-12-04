#include "qtdroidcompoundbutton_p.h"
#include "qtdroidfunctions_p.h"

QtDroidCompoundButton::QtDroidCompoundButton(QtDroidView *parent) : QtDroidButton(parent), m_checked(false)
{
}

bool QtDroidCompoundButton::isChecked() const
{
    return m_checked;
}

void QtDroidCompoundButton::setChecked(bool checked)
{
    if (updateChecked(checked))
        QtDroid::callBoolMethod(instance(), "setChecked", checked);
}

bool QtDroidCompoundButton::updateChecked(bool arg)
{
    if (arg != isChecked()) {
        m_checked = arg;
        emit checkedChanged();
        return true;
    }
    return false;
}

void QtDroidCompoundButton::toggle()
{
    QtDroid::callVoidMethod(instance(), "toggle");
}

QAndroidJniObject QtDroidCompoundButton::construct()
{
    return QAndroidJniObject("android/widget/CompoundButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidCompoundButton::inflate()
{
    QtDroidButton::inflate();

    QAndroidJniObject view = instance();
    m_listener = QAndroidJniObject("qtdroid/widget/QtCompoundButtonListener",
                                   "(Landroid/widget/CompoundButton;J)V",
                                   view.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    QtDroid::callBoolMethod(instance(), "setChecked", m_checked);
}

void QtDroidCompoundButton::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JZ)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidCompoundButton::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jboolean isChecked)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidCompoundButton *button = reinterpret_cast<QtDroidCompoundButton *>(instance);
    if (button)
        QMetaObject::invokeMethod(button, "updateChecked", Qt::QueuedConnection, Q_ARG(bool, isChecked));
}
