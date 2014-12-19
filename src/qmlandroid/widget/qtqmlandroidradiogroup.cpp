#include "qtqmlandroidradiogroup_p.h"
#include "qtqmlandroidradiobutton_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidRadioGroup::QtQmlAndroidRadioGroup(QtQmlAndroidView *parent) :
    QtQmlAndroidLinearLayout(parent), m_checkedButton(0)
{
}

QtQmlAndroidRadioButton *QtQmlAndroidRadioGroup::checkedButton() const
{
    return m_checkedButton;
}

void QtQmlAndroidRadioGroup::setCheckedButton(QtQmlAndroidRadioButton *button)
{
    if (updateCheckedButton(button))
        QtQmlAndroid::callIntMethod(instance(), "check", button ? button->identifier() : -1);
}

void QtQmlAndroidRadioGroup::clearCheck()
{
    QtQmlAndroid::callVoidMethod(instance(), "clearCheck");
}

QAndroidJniObject QtQmlAndroidRadioGroup::onCreate()
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidRadioGroup::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidLinearLayout::onInflate(instance);

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

void QtQmlAndroidRadioGroup::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JI)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidRadioGroup::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidRadioGroup *group = reinterpret_cast<QtQmlAndroidRadioGroup *>(instance);
    if (group)
        QMetaObject::invokeMethod(group, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QtQmlAndroidRadioGroup::updateCheckedButtonId(int checkedId)
{
    foreach (QObject *child, QObject::children()) {
        QtQmlAndroidRadioButton *button = qobject_cast<QtQmlAndroidRadioButton *>(child);
        if (button && button->identifier() == checkedId) {
            updateCheckedButton(button);
            return;
        }
    }
    updateCheckedButton(0);
}

bool QtQmlAndroidRadioGroup::updateCheckedButton(QtQmlAndroidRadioButton *button)
{
    if (m_checkedButton != button) {
        m_checkedButton = button;
        emit checkedButtonChanged();
        return true;
    }
    return false;
}

QT_END_NAMESPACE
