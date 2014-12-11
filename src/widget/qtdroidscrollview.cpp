#include "qtdroidscrollview_p.h"
#include "qtdroidfunctions_p.h"

QtAndroidScrollView::QtAndroidScrollView(QtAndroidView *parent) : QtAndroidFrameLayout(parent)
{
}

int QtAndroidScrollView::scrollX() const
{
    if (m_scrollX.isNull())
        return 0;
    return m_scrollX.value();
}

void QtAndroidScrollView::setScrollX(int x)
{
    if (updateScrollX(x))
        QtAndroid::callIntMethod(instance(), "setScrollX", x);
}

bool QtAndroidScrollView::updateScrollX(int x)
{
    if (m_scrollX.isNull() || m_scrollX.value() != x) {
        m_scrollX = x;
        emit scrollXChanged();
    }
    return false;
}

int QtAndroidScrollView::scrollY() const
{
    if (m_scrollY.isNull())
        return 0;
    return m_scrollY.value();
}

void QtAndroidScrollView::setScrollY(int y)
{
    if (updateScrollY(y))
        QtAndroid::callIntMethod(instance(), "setScrollY", y);
}

bool QtAndroidScrollView::updateScrollY(int y)
{
    if (m_scrollY.isNull() || m_scrollY.value() != y) {
        m_scrollY = y;
        emit scrollYChanged();
    }
    return false;
}

QAndroidJniObject QtAndroidScrollView::construct()
{
    return QAndroidJniObject("qtdroid/widget/QtScrollView",
                             "(Landroid/content/Context;J)V",
                             ctx().object(),
                             reinterpret_cast<jlong>(this));
}

void QtAndroidScrollView::inflate()
{
    QtAndroidFrameLayout::inflate();

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(instance().object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidScrollView::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onScrollChanged", "(JII)V", reinterpret_cast<void *>(onScrollChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidScrollView::onScrollChanged(JNIEnv *env, jobject object, jlong instance, jint left, jint top)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidScrollView *view = reinterpret_cast<QtAndroidScrollView *>(instance);
    if (view) {
        QMetaObject::invokeMethod(view, "updateScrollX", Qt::QueuedConnection, Q_ARG(int, left));
        QMetaObject::invokeMethod(view, "updateScrollY", Qt::QueuedConnection, Q_ARG(int, top));
    }
}
