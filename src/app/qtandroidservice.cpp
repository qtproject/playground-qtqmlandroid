#include "qtandroidservice_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidService::QtAndroidService(QObject *parent) :
    QtAndroidContextWrapper(0, parent), m_sticky(true)
{
}

bool QtAndroidService::isSticky() const
{
    return m_sticky;
}

void QtAndroidService::setSticky(bool sticky)
{
    if (m_sticky != sticky) {
        m_sticky = sticky;
        emit stickyChanged();
    }
}

void QtAndroidService::start()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtAndroid::callFunction([=]() {
        QAndroidJniObject cls = service.callObjectMethod("getClass", "()Ljava/lang/Class;");
        QAndroidJniObject intent = QAndroidJniObject("android/content/Intent",
                                                     "(Landroid/content/Context;Ljava/lang/Class;)V",
                                                     context.object(),
                                                     cls.object());
        intent.callObjectMethod("putExtra",
                                "(Ljava/lang/String;J)Landroid/content/Intent;",
                                QAndroidJniObject::fromString("QtService").object(),
                                reinterpret_cast<jlong>(this));
        QAndroidJniObject component = context.callObjectMethod("startService",
                                                               "(Landroid/content/Intent;)Landroid/content/ComponentName;",
                                                               intent.object());
        Q_UNUSED(component);
    });
}

void QtAndroidService::stop()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtAndroid::callFunction([=]() {
        QAndroidJniObject cls = service.callObjectMethod("getClass", "()Ljava/lang/Class;");
        QAndroidJniObject intent = QAndroidJniObject("android/content/Intent",
                                                     "(Landroid/content/Context;Ljava/lang/Class;)V",
                                                     context.object(),
                                                     cls.object());
        intent.callObjectMethod("putExtra",
                                "(Ljava/lang/String;J)Landroid/content/Intent;",
                                QAndroidJniObject::fromString("QtService").object(),
                                reinterpret_cast<jlong>(this));
        context.callMethod<jboolean>("stopService",
                                     "(Landroid/content/Intent;)Z",
                                     intent.object());
    });
}

QAndroidJniObject QtAndroidService::onCreate()
{
    return QAndroidJniObject("qt/android/app/QtService");
}

void QtAndroidService::onInflate(QAndroidJniObject& instance)
{
    QtAndroidContextWrapper::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QtAndroidService::onRegisterNativeMethods(jobject service)
{
    JNINativeMethod methods[] {{"onCreated", "(J)V", reinterpret_cast<void *>(onCreated)},
                               {"onDestroyed", "(J)V", reinterpret_cast<void *>(onDestroyed)},
                               {"onStartCommand", "(JII)Z", reinterpret_cast<void *>(onStartCommand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(service);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidService::onCreated(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
//    QtAndroidService *service = reinterpret_cast<QtAndroidService *>(instance);
//    if (service)
//        QMetaObject::invokeMethod(service, "created", Qt::QueuedConnection);
}

void QtAndroidService::onDestroyed(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidService *service = reinterpret_cast<QtAndroidService *>(instance);
    if (service)
        QMetaObject::invokeMethod(service, "stopped", Qt::QueuedConnection);
}

jboolean QtAndroidService::onStartCommand(JNIEnv *env, jobject object, jlong instance, jint flags, jint startId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidService *service = reinterpret_cast<QtAndroidService *>(instance);
    bool ret = false;
    if (service) {
        QMetaObject::invokeMethod(service, "startCommand", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, ret), Q_ARG(int, flags), Q_ARG(int, startId));
        QMetaObject::invokeMethod(service, "started", Qt::QueuedConnection);
    }
    return ret;
}

bool QtAndroidService::startCommand(int flags, int startId)
{
    Q_UNUSED(flags);
    Q_UNUSED(startId);
    return m_sticky;
}

QT_END_NAMESPACE
