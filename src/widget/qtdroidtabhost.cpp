#include "qtdroidtabhost_p.h"
#include "qtdroidtabspec_p.h"

QtDroidTabHost::QtDroidTabHost(QtDroidView *parent) : QtDroidFrameLayout(parent)
{
}

QAndroidJniObject QtDroidTabHost::construct(jobject context)
{
    return QAndroidJniObject("android/widget/TabHost",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;)V",
                             context, 0);
}

void QtDroidTabHost::inflate(jobject context)
{
    QtDroidFrameLayout::inflate(context);

    QAndroidJniObject host = instance();
    m_listener = QAndroidJniObject("qtdroid/widget/QtTabHostListener",
                                   "(Landroid/widget/TabHost;J)V",
                                   host.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    host.callMethod<void>("setup");

    int i = 0;
    QList<QtDroidTabSpec *> tabs = findChildren<QtDroidTabSpec *>();
    foreach (QtDroidTabSpec *tab, tabs) {
        QAndroidJniObject spec = host.callObjectMethod("newTabSpec",
                                                       "(Ljava/lang/String;)Landroid/widget/TabHost$TabSpec;",
                                                       QAndroidJniObject::fromString(QString::number(i++)).object());
        tab->applyParams(spec);
        host.callMethod<void>("addTab", "(Landroid/widget/TabHost$TabSpec;)V", spec.object());
    }
}

void QtDroidTabHost::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onTabChanged", "(JLjava/lang/String;)V", reinterpret_cast<void *>(onTabChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

#include <QtDebug>
void QtDroidTabHost::onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidTabHost *host = reinterpret_cast<QtDroidTabHost *>(instance);
    if (host) {
        qDebug() << host << QAndroidJniObject(tabId).toString();
        QMetaObject::invokeMethod(host, "tabChanged", Qt::QueuedConnection, Q_ARG(QString, QAndroidJniObject(tabId).toString()));
    }
}
