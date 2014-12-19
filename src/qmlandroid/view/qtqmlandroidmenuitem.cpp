#include "qtqmlandroidmenuitem_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidcontext_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidMenuItem::QtQmlAndroidMenuItem(QObject *parent) :
    QtQmlAndroidContextual(parent), m_enabled(true), m_visible(true),
    m_checkable(false), m_checked(false),
    m_showAs(0), // TODO: SHOW_AS_ACTION_NEVER
    m_actionView(0)
{
}

QString QtQmlAndroidMenuItem::title() const
{
    return m_title;
}

void QtQmlAndroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

bool QtQmlAndroidMenuItem::isEnabled() const
{
    return m_enabled;
}

void QtQmlAndroidMenuItem::setEnabled(bool enabled)
{
    if (m_enabled != enabled) {
        m_enabled = enabled;
        QtQmlAndroid::callBoolMethod(instance(), "setEnabled", enabled);
        emit enabledChanged();
    }
}

bool QtQmlAndroidMenuItem::isVisible() const
{
    return m_visible;
}

void QtQmlAndroidMenuItem::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        QtQmlAndroid::callBoolMethod(instance(), "setVisible", visible);
        if (isValid() && context())
            QMetaObject::invokeMethod(context(), "invalidateOptionsMenu");
        emit visibleChanged();
    }
}

bool QtQmlAndroidMenuItem::isCheckable() const
{
    return m_checkable;
}

void QtQmlAndroidMenuItem::setCheckable(bool checkable)
{
    if (m_checkable != checkable) {
        m_checkable = checkable;
        QtQmlAndroid::callBoolMethod(instance(), "setCheckable", checkable);
        emit checkableChanged();
    }
}

bool QtQmlAndroidMenuItem::isChecked() const
{
    return m_checked;
}

void QtQmlAndroidMenuItem::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        QtQmlAndroid::callBoolMethod(instance(), "setChecked", checked);
        emit checkedChanged();
    }
}

int QtQmlAndroidMenuItem::showAs() const
{
    return m_showAs;
}

void QtQmlAndroidMenuItem::setShowAs(int showAs)
{
    if (m_showAs != showAs) {
        m_showAs = showAs;
        QtQmlAndroid::callIntMethod(instance(), "setShowAs", showAs);
        emit showAsChanged();
    }
}

QtQmlAndroidView *QtQmlAndroidMenuItem::actionView() const
{
    return m_actionView;
}

void QtQmlAndroidMenuItem::setActionView(QtQmlAndroidView *view)
{
    if (m_actionView != view) {
        if (m_actionView) {
            disconnect(m_actionView, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidMenuItem::updateActionView);
            m_actionView->destruct();
        }
        m_actionView = view;
        if (m_actionView) {
            connect(m_actionView, &QtQmlAndroidObject::instanceChanged, this, &QtQmlAndroidMenuItem::updateActionView);
            if (isValid())
                m_actionView->construct();
        }
        emit actionViewChanged();
    }
}

QAndroidJniObject QtQmlAndroidMenuItem::onCreate()
{
    return QAndroidJniObject("qt/android/view/QtMenuItem",
                             "(J)V",
                             reinterpret_cast<jlong>(this));
}

void QtQmlAndroidMenuItem::onInflate(QAndroidJniObject &instance)
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

void QtQmlAndroidMenuItem::onRegisterNativeMethods(jobject item)
{
    JNINativeMethod methods[] {{"onClick", "(J)Z", reinterpret_cast<void *>(onClick)},
                               {"onMenuItemActionCollapse", "(J)Z", reinterpret_cast<void *>(onMenuItemActionCollapse)},
                               {"onMenuItemActionExpand", "(J)Z", reinterpret_cast<void *>(onMenuItemActionExpand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(item);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

bool QtQmlAndroidMenuItem::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidMenuItem *item = reinterpret_cast<QtQmlAndroidMenuItem *>(instance);
    if (item) {
        QMetaObject::invokeMethod(item, "click", Qt::QueuedConnection);
        return true;
    }
    return false;
}

bool QtQmlAndroidMenuItem::onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidMenuItem *item = reinterpret_cast<QtQmlAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;
}

bool QtQmlAndroidMenuItem::onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidMenuItem *item = reinterpret_cast<QtQmlAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;

}

void QtQmlAndroidMenuItem::objectChange(ObjectChange change)
{
    QtQmlAndroidContextual::objectChange(change);
    if (change == InstanceChange)
        updateActionView();
}

void QtQmlAndroidMenuItem::updateActionView()
{
    if (!isValid() || !m_actionView)
        return;

    QAndroidJniObject item = instance();
    QAndroidJniObject view = m_actionView->instance();
    QtQmlAndroid::callFunction([=]() {
        item.callMethod<void>("setActionView", "(Landroid/view/View;)V", view.object());
    });
}

QT_END_NAMESPACE
