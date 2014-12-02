#include "qtdroidradiogroup_p.h"
#include "qtdroidradiobutton_p.h"

QtDroidRadioGroup::QtDroidRadioGroup(QObject *parent) :
    QtDroidLinearLayout(parent), m_checkedButton(0)
{
}

QtDroidRadioButton *QtDroidRadioGroup::checkedButton() const
{
    return m_checkedButton;
}

void QtDroidRadioGroup::setCheckedButton(QtDroidRadioButton *button)
{
    if (updateCheckedButton(button))
        callIntMethod("check", button ? button->identifier() : -1);
}

void QtDroidRadioGroup::clearCheck()
{
    callVoidMethod("clearCheck");
}

QAndroidJniObject QtDroidRadioGroup::construct(jobject context)
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidRadioGroup::inflate(jobject context)
{
    QtDroidLinearLayout::inflate(context);

    QAndroidJniObject group = instance();
    m_listener = QAndroidJniObject("qtdroid/widget/QtRadioGroupListener",
                                   "(Landroid/widget/RadioGroup;J)V",
                                   group.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    int checkedId = group.callMethod<int>("getCheckedRadioButtonId", "()I");
    QMetaObject::invokeMethod(this, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QtDroidRadioGroup::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JI)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidRadioGroup::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidRadioGroup *group = reinterpret_cast<QtDroidRadioGroup *>(instance);
    if (group)
        QMetaObject::invokeMethod(group, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QtDroidRadioGroup::updateCheckedButtonId(int checkedId)
{
    foreach (QObject *child, QObject::children()) {
        QtDroidRadioButton *button = qobject_cast<QtDroidRadioButton *>(child);
        if (button && button->identifier() == checkedId) {
            updateCheckedButton(button);
            return;
        }
    }
    updateCheckedButton(0);
}

bool QtDroidRadioGroup::updateCheckedButton(QtDroidRadioButton *button)
{
    if (m_checkedButton != button) {
        m_checkedButton = button;
        emit checkedButtonChanged();
        return true;
    }
    return false;
}
