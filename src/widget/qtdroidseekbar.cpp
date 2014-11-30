#include "qtdroidseekbar_p.h"

QtDroidSeekBar::QtDroidSeekBar(QObject *parent) : QtDroidAbsSeekBar(parent)
{
}

QAndroidJniObject QtDroidSeekBar::construct(jobject context)
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidSeekBar::inflate(jobject context)
{
    QtDroidAbsSeekBar::inflate(context);

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
