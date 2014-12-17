#include "qtandroidmenuitem_p.h"
#include "qtandroidfunctions_p.h"
#include "qtandroidcontext_p.h"
#include "qtandroidview_p.h"

QtAndroidMenuItem::QtAndroidMenuItem(QObject *parent) :
    QtAndroidContextual(parent), m_enabled(true), m_visible(true),
    m_checkable(false), m_checked(false),
    m_showAs(0), // TODO: SHOW_AS_ACTION_NEVER
    m_actionView(0)
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
        if (isValid() && context())
            QMetaObject::invokeMethod(context(), "invalidateOptionsMenu");
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

int QtAndroidMenuItem::showAs() const
{
    return m_showAs;
}

void QtAndroidMenuItem::setShowAs(int showAs)
{
    if (m_showAs != showAs) {
        m_showAs = showAs;
        QtAndroid::callIntMethod(instance(), "setShowAs", showAs);
        emit showAsChanged();
    }
}

QtAndroidView *QtAndroidMenuItem::actionView() const
{
    return m_actionView;
}

void QtAndroidMenuItem::setActionView(QtAndroidView *view)
{
    if (m_actionView != view) {
        if (m_actionView) {
            disconnect(m_actionView, &QtAndroidObject::instanceChanged, this, &QtAndroidMenuItem::updateActionView);
            m_actionView->destruct();
        }
        m_actionView = view;
        if (m_actionView) {
            connect(m_actionView, &QtAndroidObject::instanceChanged, this, &QtAndroidMenuItem::updateActionView);
            if (isValid())
                m_actionView->construct();
        }
        emit actionViewChanged();
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
    instance.callMethod<void>("setShowAs", "(I)V", m_showAs);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidMenuItem::onRegisterNativeMethods(jobject item)
{
    JNINativeMethod methods[] {{"onClick", "(J)Z", reinterpret_cast<void *>(onClick)},
                               {"onMenuItemActionCollapse", "(J)Z", reinterpret_cast<void *>(onMenuItemActionCollapse)},
                               {"onMenuItemActionExpand", "(J)Z", reinterpret_cast<void *>(onMenuItemActionExpand)}};

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

bool QtAndroidMenuItem::onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidMenuItem *item = reinterpret_cast<QtAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;
}

bool QtAndroidMenuItem::onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidMenuItem *item = reinterpret_cast<QtAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;

}

void QtAndroidMenuItem::objectChange(ObjectChange change)
{
    QtAndroidContextual::objectChange(change);
    if (change == InstanceChange)
        updateActionView();
}

void QtAndroidMenuItem::updateActionView()
{
    if (!isValid() || !m_actionView)
        return;

    QAndroidJniObject item = instance();
    QAndroidJniObject view = m_actionView->instance();
    QtAndroid::callFunction([=]() {
        item.callMethod<void>("setActionView", "(Landroid/view/View;)V", view.object());
    });
}
