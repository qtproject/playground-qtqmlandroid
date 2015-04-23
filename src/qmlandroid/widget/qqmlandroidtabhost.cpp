#include "qqmlandroidtabhost_p.h"
#include "qqmlandroidtabspec_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidTabHost::QQmlAndroidTabHost(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QQmlAndroidTabHost::onCreate()
{
    return QAndroidJniObject("android/widget/TabHost",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;)V",
                             ctx().object(), 0);
}

void QQmlAndroidTabHost::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QmlTabHostListener",
                                   "(Landroid/widget/TabHost;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setup");

    int index = 0;
    QList<QQmlAndroidTabSpec *> tabs = findChildren<QQmlAndroidTabSpec *>();
    foreach (QQmlAndroidTabSpec *tab, tabs)
        tab->setup(instance, index++);
}

void QQmlAndroidTabHost::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onTabChanged", "(JLjava/lang/String;)V", reinterpret_cast<void *>(onTabChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidTabHost::onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidTabHost *host = reinterpret_cast<QQmlAndroidTabHost *>(instance);
    if (host)
        QMetaObject::invokeMethod(host, "tabChanged", Qt::QueuedConnection, Q_ARG(QString, QAndroidJniObject(tabId).toString()));
}

QT_END_NAMESPACE
