#include "qtqmlandroidseekbar_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSeekBar::QtQmlAndroidSeekBar(QtQmlAndroidView *parent) :
    QtQmlAndroidAbsSeekBar(parent)
{
}

QAndroidJniObject QtQmlAndroidSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSeekBar::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidAbsSeekBar::onInflate(instance);

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

void QtQmlAndroidSeekBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onProgressChanged", "(JIZ)V", reinterpret_cast<void *>(onProgressChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidSeekBar::onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidSeekBar *bar = reinterpret_cast<QtQmlAndroidSeekBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateProgress", Qt::QueuedConnection, Q_ARG(int, progress));
}

QT_END_NAMESPACE
