#include "qtqmlandroidswiperefreshlayout_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSwipeRefreshLayout::QtQmlAndroidSwipeRefreshLayout(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent), m_refreshing(false)
{
}

bool QtQmlAndroidSwipeRefreshLayout::isRefreshing() const
{
    return m_refreshing;
}

void QtQmlAndroidSwipeRefreshLayout::setRefreshing(bool refreshing)
{
    if (updateRefreshing(refreshing))
        QtQmlAndroid::callBoolMethod(instance(), "setRefreshing", refreshing);
}

bool QtQmlAndroidSwipeRefreshLayout::updateRefreshing(bool refreshing)
{
    if (m_refreshing != refreshing) {
        m_refreshing = refreshing;
        emit refreshingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QtQmlAndroidSwipeRefreshLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/SwipeRefreshLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSwipeRefreshLayout::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewGroup::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/support/v4/widget/QtSwipeRefreshLayoutListener",
                                   "(Landroid/support/v4/widget/SwipeRefreshLayout;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtQmlAndroidSwipeRefreshLayout::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRefresh", "(J)V", reinterpret_cast<void *>(onRefresh)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidSwipeRefreshLayout::onRefresh(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidSwipeRefreshLayout *layout = reinterpret_cast<QtQmlAndroidSwipeRefreshLayout *>(instance);
    if (layout)
        QMetaObject::invokeMethod(layout, "updateRefreshing", Qt::QueuedConnection, Q_ARG(bool, true));
}

QT_END_NAMESPACE
