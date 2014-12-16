#include "qtandroidradiogroup_p.h"
#include "qtandroidradiobutton_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidRadioGroup::QtAndroidRadioGroup(QtAndroidView *parent) :
    QtAndroidLinearLayout(parent), m_checkedButton(0)
{
}

QtAndroidRadioButton *QtAndroidRadioGroup::checkedButton() const
{
    return m_checkedButton;
}

void QtAndroidRadioGroup::setCheckedButton(QtAndroidRadioButton *button)
{
    if (updateCheckedButton(button))
        QtAndroid::callIntMethod(instance(), "check", button ? button->identifier() : -1);
}

void QtAndroidRadioGroup::clearCheck()
{
    QtAndroid::callVoidMethod(instance(), "clearCheck");
}

QAndroidJniObject QtAndroidRadioGroup::onCreate()
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRadioGroup::onInflate(QAndroidJniObject &instance)
{
    QtAndroidLinearLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtRadioGroupListener",
                                   "(Landroid/widget/RadioGroup;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    int checkedId = instance.callMethod<int>("getCheckedRadioButtonId", "()I");
    QMetaObject::invokeMethod(this, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QtAndroidRadioGroup::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JI)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidRadioGroup::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidRadioGroup *group = reinterpret_cast<QtAndroidRadioGroup *>(instance);
    if (group)
        QMetaObject::invokeMethod(group, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QtAndroidRadioGroup::updateCheckedButtonId(int checkedId)
{
    foreach (QObject *child, QObject::children()) {
        QtAndroidRadioButton *button = qobject_cast<QtAndroidRadioButton *>(child);
        if (button && button->identifier() == checkedId) {
            updateCheckedButton(button);
            return;
        }
    }
    updateCheckedButton(0);
}

bool QtAndroidRadioGroup::updateCheckedButton(QtAndroidRadioButton *button)
{
    if (m_checkedButton != button) {
        m_checkedButton = button;
        emit checkedButtonChanged();
        return true;
    }
    return false;
}
