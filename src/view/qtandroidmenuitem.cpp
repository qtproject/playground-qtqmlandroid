#include "qtandroidmenuitem_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidMenuItem::QtAndroidMenuItem(QObject *parent) :
    QtAndroidObject(parent), m_enabled(true), m_visible(true), m_checkable(false), m_checked(false)
{
}

QString QtAndroidMenuItem::title() const
{
    return m_title;
}

void QtAndroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

bool QtAndroidMenuItem::isEnabled() const
{
    return m_enabled;
}

void QtAndroidMenuItem::setEnabled(bool enabled)
{
    if (m_enabled != enabled) {
        m_enabled = enabled;
        QtAndroid::callBoolMethod(instance(), "setEnabled", enabled);
        emit enabledChanged();
    }
}

bool QtAndroidMenuItem::isVisible() const
{
    return m_visible;
}

void QtAndroidMenuItem::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        QtAndroid::callBoolMethod(instance(), "setVisible", visible);
        emit visibleChanged();
    }
}

bool QtAndroidMenuItem::isCheckable() const
{
    return m_checkable;
}

void QtAndroidMenuItem::setCheckable(bool checkable)
{
    if (m_checkable != checkable) {
        m_checkable = checkable;
        QtAndroid::callBoolMethod(instance(), "setCheckable", checkable);
        emit checkableChanged();
    }
}

bool QtAndroidMenuItem::isChecked() const
{
    return m_checked;
}

void QtAndroidMenuItem::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        QtAndroid::callBoolMethod(instance(), "setChecked", checked);
        emit checkedChanged();
    }
}

QAndroidJniObject QtAndroidMenuItem::onCreate()
{
    return QAndroidJniObject("qt/android/view/QtMenuItem",
                             "(J)V",
                             reinterpret_cast<jlong>(this));
}

void QtAndroidMenuItem::onInflate(QAndroidJniObject &instance)
{
    instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    instance.callMethod<void>("setEnabled", "(Z)V", m_enabled);
    instance.callMethod<void>("setVisible", "(Z)V", m_visible);
    instance.callMethod<void>("setCheckable", "(Z)V", m_checkable);
    instance.callMethod<void>("setChecked", "(Z)V", m_enabled);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidMenuItem::onRegisterNativeMethods(jobject item)
{
    JNINativeMethod methods[] {{"onClick", "(J)Z", reinterpret_cast<void *>(onClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(item);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

bool QtAndroidMenuItem::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidMenuItem *item = reinterpret_cast<QtAndroidMenuItem *>(instance);
    if (item) {
        QMetaObject::invokeMethod(item, "click", Qt::QueuedConnection);
        return true;
    }
    return false;
}
