#include "qtdroidseekbar_p.h"

QtDroidSeekBar::QtDroidSeekBar(QtDroidView *parent) : QtDroidAbsSeekBar(parent)
{
}

QAndroidJniObject QtDroidSeekBar::construct()
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidSeekBar::inflate()
{
    QtDroidAbsSeekBar::inflate();

    QAndroidJniObject bar = instance();
    m_listener = QAndroidJniObject("qtdroid/widget/QtSeekBarListener",
                                   "(Landroid/widget/SeekBar;J)V",
                                   bar.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtDroidSeekBar::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onProgressChanged", "(JIZ)V", reinterpret_cast<void *>(onProgressChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtDroidSeekBar::onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtDroidSeekBar *bar = reinterpret_cast<QtDroidSeekBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateProgress", Qt::QueuedConnection, Q_ARG(int, progress));
}
