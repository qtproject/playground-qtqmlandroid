#include "qtqmlandroidradiogroup_p.h"
#include "qtqmlandroidradiobutton_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRadioGroup::QQmlAndroidRadioGroup(QQmlAndroidView *parent) :
    QQmlAndroidLinearLayout(parent), m_checkedButton(0)
{
}

QQmlAndroidRadioButton *QQmlAndroidRadioGroup::checkedButton() const
{
    return m_checkedButton;
}

void QQmlAndroidRadioGroup::setCheckedButton(QQmlAndroidRadioButton *button)
{
    if (updateCheckedButton(button))
        QtQmlAndroid::callIntMethod(instance(), "check", button ? button->identifier() : -1);
}

void QQmlAndroidRadioGroup::clearCheck()
{
    QtQmlAndroid::callVoidMethod(instance(), "clearCheck");
}

QAndroidJniObject QQmlAndroidRadioGroup::onCreate()
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRadioGroup::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLinearLayout::onInflate(instance);

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

void QQmlAndroidRadioGroup::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JI)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidRadioGroup::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidRadioGroup *group = reinterpret_cast<QQmlAndroidRadioGroup *>(instance);
    if (group)
        QMetaObject::invokeMethod(group, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QQmlAndroidRadioGroup::updateCheckedButtonId(int checkedId)
{
    foreach (QObject *child, QObject::children()) {
        QQmlAndroidRadioButton *button = qobject_cast<QQmlAndroidRadioButton *>(child);
        if (button && button->identifier() == checkedId) {
            updateCheckedButton(button);
            return;
        }
    }
    updateCheckedButton(0);
}

bool QQmlAndroidRadioGroup::updateCheckedButton(QQmlAndroidRadioButton *button)
{
    if (m_checkedButton != button) {
        m_checkedButton = button;
        emit checkedButtonChanged();
        return true;
    }
    return false;
}

QT_END_NAMESPACE
