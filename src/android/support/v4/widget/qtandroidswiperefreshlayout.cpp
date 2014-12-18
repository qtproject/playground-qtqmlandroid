#include "qtandroidswiperefreshlayout_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidSwipeRefreshLayout::QtAndroidSwipeRefreshLayout(QtAndroidView *parent) :
    QtAndroidViewGroup(parent), m_refreshing(false)
{
}

bool QtAndroidSwipeRefreshLayout::isRefreshing() const
{
    return m_refreshing;
}

void QtAndroidSwipeRefreshLayout::setRefreshing(bool refreshing)
{
    if (updateRefreshing(refreshing))
        QtAndroid::callBoolMethod(instance(), "setRefreshing", refreshing);
}

bool QtAndroidSwipeRefreshLayout::updateRefreshing(bool refreshing)
{
    if (m_refreshing != refreshing) {
        m_refreshing = refreshing;
        emit refreshingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QtAndroidSwipeRefreshLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/SwipeRefreshLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSwipeRefreshLayout::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewGroup::onInflate(instance);

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

void QtAndroidSwipeRefreshLayout::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRefresh", "(J)V", reinterpret_cast<void *>(onRefresh)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidSwipeRefreshLayout::onRefresh(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidSwipeRefreshLayout *layout = reinterpret_cast<QtAndroidSwipeRefreshLayout *>(instance);
    if (layout)
        QMetaObject::invokeMethod(layout, "updateRefreshing", Qt::QueuedConnection, Q_ARG(bool, true));
}

QT_END_NAMESPACE
