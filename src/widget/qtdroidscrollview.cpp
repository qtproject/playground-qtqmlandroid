#include "qtdroidscrollview_p.h"
#include "qtdroidfunctions_p.h"

QtDroidScrollView::QtDroidScrollView(QtDroidView *parent) : QtDroidFrameLayout(parent)
{
}

int QtDroidScrollView::scrollX() const
{
    if (m_scrollX.isNull())
        return 0;
    return m_scrollX.value();
}

void QtDroidScrollView::setScrollX(int x)
{
    if (updateScrollX(x))
        QtDroid::callIntMethod(instance(), "setScrollX", x);
}

bool QtDroidScrollView::updateScrollX(int x)
{
    if (m_scrollX.isNull() || m_scrollX.value() != x) {
        m_scrollX = x;
        emit scrollXChanged();
    }
    return false;
}

int QtDroidScrollView::scrollY() const
{
    if (m_scrollY.isNull())
        return 0;
    return m_scrollY.value();
}

void QtDroidScrollView::setScrollY(int y)
{
    if (updateScrollY(y))
        QtDroid::callIntMethod(instance(), "setScrollY", y);
}

bool QtDroidScrollView::updateScrollY(int y)
{
    if (m_scrollY.isNull() || m_scrollY.value() != y) {
        m_scrollY = y;
        emit scrollYChanged();
    }
    return false;
}

QAndroidJniObject QtDroidScrollView::construct()
{
    return QAndroidJniObject("qtdroid/widget/QtScrollView",
                             "(Landroid/content/Context;J)V",
                             ctx().object(),
                             reinterpret_cast<jlong>(this));
}

void QtDroidScrollView::inflate()
{
    QtDroidFrameLayout::inflate();

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(instance().object());
        nativeMethodsRegistered = true;
    }
}

void QtDroidScrollView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onScrollChanged", "(JII)V", reinterpret_cast<void *>(onScrollChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidScrollView::onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidScrollView *view = reinterpret_cast<QtDroidScrollView *>(instance);
    if (view) {
        QMetaObject::invokeMethod(view, "updateScrollX", Qt::QueuedConnection, Q_ARG(int, left));
        QMetaObject::invokeMethod(view, "updateScrollY", Qt::QueuedConnection, Q_ARG(int, top));
    }
}
