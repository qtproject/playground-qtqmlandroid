#include "qtandroidseekbar_p.h"

QtAndroidSeekBar::QtAndroidSeekBar(QtAndroidView *parent) :
    QtAndroidAbsSeekBar(parent)
{
}

QAndroidJniObject QtAndroidSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSeekBar::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAbsSeekBar::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtSeekBarListener",
                                   "(Landroid/widget/SeekBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        registerNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidSeekBar::registerNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onProgressChanged", "(JIZ)V", reinterpret_cast<void *>(onProgressChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidSeekBar::onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidSeekBar *bar = reinterpret_cast<QtAndroidSeekBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateProgress", Qt::QueuedConnection, Q_ARG(int, progress));
}
