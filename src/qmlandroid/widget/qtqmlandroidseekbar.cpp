#include "qtqmlandroidseekbar_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSeekBar::QQmlAndroidSeekBar(QQmlAndroidView *parent) :
    QQmlAndroidAbsSeekBar(parent)
{
}

QAndroidJniObject QQmlAndroidSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSeekBar::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidAbsSeekBar::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtSeekBarListener",
                                   "(Landroid/widget/SeekBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QQmlAndroidSeekBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onProgressChanged", "(JIZ)V", reinterpret_cast<void *>(onProgressChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidSeekBar::onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidSeekBar *bar = reinterpret_cast<QQmlAndroidSeekBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateProgress", Qt::QueuedConnection, Q_ARG(int, progress));
}

QT_END_NAMESPACE
