#include "qqmlandroidscrollview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidScrollView::QQmlAndroidScrollView(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

int QQmlAndroidScrollView::scrollX() const
{
    if (m_scrollX.isNull())
        return 0;
    return m_scrollX.value();
}

void QQmlAndroidScrollView::setScrollX(int x)
{
    if (updateScrollX(x))
        QtQmlAndroid::callIntMethod(instance(), "setScrollX", x);
}

bool QQmlAndroidScrollView::updateScrollX(int x)
{
    if (m_scrollX.isNull() || m_scrollX.value() != x) {
        m_scrollX = x;
        emit scrollXChanged();
    }
    return false;
}

int QQmlAndroidScrollView::scrollY() const
{
    if (m_scrollY.isNull())
        return 0;
    return m_scrollY.value();
}

void QQmlAndroidScrollView::setScrollY(int y)
{
    if (updateScrollY(y))
        QtQmlAndroid::callIntMethod(instance(), "setScrollY", y);
}

bool QQmlAndroidScrollView::updateScrollY(int y)
{
    if (m_scrollY.isNull() || m_scrollY.value() != y) {
        m_scrollY = y;
        emit scrollYChanged();
    }
    return false;
}

QAndroidJniObject QQmlAndroidScrollView::onCreate()
{
    return QAndroidJniObject("qt/android/widget/QtScrollView",
                             "(Landroid/content/Context;J)V",
                             ctx().object(),
                             reinterpret_cast<jlong>(this));
}

void QQmlAndroidScrollView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QQmlAndroidScrollView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onScrollChanged", "(JII)V", reinterpret_cast<void *>(onScrollChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidScrollView::onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidScrollView *view = reinterpret_cast<QQmlAndroidScrollView *>(instance);
    if (view) {
        QMetaObject::invokeMethod(view, "updateScrollX", Qt::QueuedConnection, Q_ARG(int, left));
        QMetaObject::invokeMethod(view, "updateScrollY", Qt::QueuedConnection, Q_ARG(int, top));
    }
}

QT_END_NAMESPACE
