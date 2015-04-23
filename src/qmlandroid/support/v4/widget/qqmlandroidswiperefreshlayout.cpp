#include "qqmlandroidswiperefreshlayout_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSwipeRefreshLayout::QQmlAndroidSwipeRefreshLayout(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent), m_refreshing(false)
{
}

bool QQmlAndroidSwipeRefreshLayout::isRefreshing() const
{
    return m_refreshing;
}

void QQmlAndroidSwipeRefreshLayout::setRefreshing(bool refreshing)
{
    if (updateRefreshing(refreshing))
        QtQmlAndroid::callBoolMethod(instance(), "setRefreshing", refreshing);
}

bool QQmlAndroidSwipeRefreshLayout::updateRefreshing(bool refreshing)
{
    if (m_refreshing != refreshing) {
        m_refreshing = refreshing;
        emit refreshingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QQmlAndroidSwipeRefreshLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/SwipeRefreshLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSwipeRefreshLayout::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewGroup::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/support/v4/widget/QmlSwipeRefreshLayoutListener",
                                   "(Landroid/support/v4/widget/SwipeRefreshLayout;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QQmlAndroidSwipeRefreshLayout::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRefresh", "(J)V", reinterpret_cast<void *>(onRefresh)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidSwipeRefreshLayout::onRefresh(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidSwipeRefreshLayout *layout = reinterpret_cast<QQmlAndroidSwipeRefreshLayout *>(instance);
    if (layout)
        QMetaObject::invokeMethod(layout, "updateRefreshing", Qt::QueuedConnection, Q_ARG(bool, true));
}

QT_END_NAMESPACE
