#include "qtqmlandroidtabhost_p.h"
#include "qtqmlandroidtabspec_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidTabHost::QtQmlAndroidTabHost(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidTabHost::onCreate()
{
    return QAndroidJniObject("android/widget/TabHost",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;)V",
                             ctx().object(), 0);
}

void QtQmlAndroidTabHost::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtTabHostListener",
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
    QList<QtQmlAndroidTabSpec *> tabs = findChildren<QtQmlAndroidTabSpec *>();
    foreach (QtQmlAndroidTabSpec *tab, tabs)
        tab->setup(instance, index++);
}

void QtQmlAndroidTabHost::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onTabChanged", "(JLjava/lang/String;)V", reinterpret_cast<void *>(onTabChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidTabHost::onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidTabHost *host = reinterpret_cast<QtQmlAndroidTabHost *>(instance);
    if (host)
        QMetaObject::invokeMethod(host, "tabChanged", Qt::QueuedConnection, Q_ARG(QString, QAndroidJniObject(tabId).toString()));
}

QT_END_NAMESPACE
