#include "qtqmlandroidservice_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidService::QtQmlAndroidService(QObject *parent) :
    QtQmlAndroidContextWrapper(0, parent), m_sticky(true)
{
}

bool QtQmlAndroidService::isSticky() const
{
    return m_sticky;
}

void QtQmlAndroidService::setSticky(bool sticky)
{
    if (m_sticky != sticky) {
        m_sticky = sticky;
        emit stickyChanged();
    }
}

void QtQmlAndroidService::start()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtQmlAndroid::callFunction([=]() {
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

void QtQmlAndroidService::stop()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtQmlAndroid::callFunction([=]() {
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

QAndroidJniObject QtQmlAndroidService::onCreate()
{
    return QAndroidJniObject("qt/android/app/QtService");
}

void QtQmlAndroidService::onInflate(QAndroidJniObject& instance)
{
    QtQmlAndroidContextWrapper::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QtQmlAndroidService::onRegisterNativeMethods(jobject service)
{
    JNINativeMethod methods[] {{"onCreated", "(J)V", reinterpret_cast<void *>(onCreated)},
                               {"onDestroyed", "(J)V", reinterpret_cast<void *>(onDestroyed)},
                               {"onStartCommand", "(JII)Z", reinterpret_cast<void *>(onStartCommand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(service);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtQmlAndroidService::onCreated(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
//    QtQmlAndroidService *service = reinterpret_cast<QtQmlAndroidService *>(instance);
//    if (service)
//        QMetaObject::invokeMethod(service, "created", Qt::QueuedConnection);
}

void QtQmlAndroidService::onDestroyed(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidService *service = reinterpret_cast<QtQmlAndroidService *>(instance);
    if (service)
        QMetaObject::invokeMethod(service, "stopped", Qt::QueuedConnection);
}

jboolean QtQmlAndroidService::onStartCommand(JNIEnv *env, jobject object, jlong instance, jint flags, jint startId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtQmlAndroidService *service = reinterpret_cast<QtQmlAndroidService *>(instance);
    bool ret = false;
    if (service) {
        QMetaObject::invokeMethod(service, "startCommand", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, ret), Q_ARG(int, flags), Q_ARG(int, startId));
        QMetaObject::invokeMethod(service, "started", Qt::QueuedConnection);
    }
    return ret;
}

bool QtQmlAndroidService::startCommand(int flags, int startId)
{
    Q_UNUSED(flags);
    Q_UNUSED(startId);
    return m_sticky;
}

QT_END_NAMESPACE
