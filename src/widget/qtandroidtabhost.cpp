#include "qtandroidtabhost_p.h"
#include "qtandroidtabspec_p.h"

QtAndroidTabHost::QtAndroidTabHost(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidTabHost::onCreate()
{
    return QAndroidJniObject("android/widget/TabHost",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;)V",
                             ctx().object(), 0);
}

void QtAndroidTabHost::onInflate(QAndroidJniObject &instance)
{
    QtAndroidFrameLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtTabHostListener",
                                   "(Landroid/widget/TabHost;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setup");

    int index = 0;
    QList<QtAndroidTabSpec *> tabs = findChildren<QtAndroidTabSpec *>();
    foreach (QtAndroidTabSpec *tab, tabs)
        tab->setup(instance, index++);
}

void QtAndroidTabHost::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onTabChanged", "(JLjava/lang/String;)V", reinterpret_cast<void *>(onTabChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidTabHost::onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidTabHost *host = reinterpret_cast<QtAndroidTabHost *>(instance);
    if (host)
        QMetaObject::invokeMethod(host, "tabChanged", Qt::QueuedConnection, Q_ARG(QString, QAndroidJniObject(tabId).toString()));
}
