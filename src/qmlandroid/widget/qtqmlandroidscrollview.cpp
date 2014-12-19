#include "qtqmlandroidscrollview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidScrollView::QtQmlAndroidScrollView(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

int QtQmlAndroidScrollView::scrollX() const
{
    if (m_scrollX.isNull())
        return 0;
    return m_scrollX.value();
}

void QtQmlAndroidScrollView::setScrollX(int x)
{
    if (updateScrollX(x))
        QtQmlAndroid::callIntMethod(instance(), "setScrollX", x);
}

bool QtQmlAndroidScrollView::updateScrollX(int x)
{
    if (m_scrollX.isNull() || m_scrollX.value() != x) {
        m_scrollX = x;
        emit scrollXChanged();
    }
    return false;
}

int QtQmlAndroidScrollView::scrollY() const
{
    if (m_scrollY.isNull())
        return 0;
    return m_scrollY.value();
}

void QtQmlAndroidScrollView::setScrollY(int y)
{
    if (updateScrollY(y))
        QtQmlAndroid::callIntMethod(instance(), "setScrollY", y);
}

bool QtQmlAndroidScrollView::updateScrollY(int y)
{
    if (m_scrollY.isNull() || m_scrollY.value() != y) {
        m_scrollY = y;
        emit scrollYChanged();
    }
    return false;
}

QAndroidJniObject QtQmlAndroidScrollView::onCreate()
{
    return QAndroidJniObject("qt/android/widget/QtScrollView",
                             "(Landroid/content/Context;J)V",
                             ctx().object(),
                             reinterpret_cast<jlong>(this));
}

void QtQmlAndroidScrollView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QtQmlAndroidScrollView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onScrollChanged", "(JII)V", reinterpret_cast<void *>(onScrollChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidScrollView::onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidScrollView *view = reinterpret_cast<QtQmlAndroidScrollView *>(instance);
    if (view) {
        QMetaObject::invokeMethod(view, "updateScrollX", Qt::QueuedConnection, Q_ARG(int, left));
        QMetaObject::invokeMethod(view, "updateScrollY", Qt::QueuedConnection, Q_ARG(int, top));
    }
}

QT_END_NAMESPACE
