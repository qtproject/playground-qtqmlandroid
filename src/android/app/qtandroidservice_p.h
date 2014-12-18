#ifndef QTANDROIDSERVICE_P_H
#define QTANDROIDSERVICE_P_H

#include "qtandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidService : public QtAndroidContextWrapper
{
    Q_OBJECT
    Q_PROPERTY(bool sticky READ isSticky WRITE setSticky NOTIFY stickyChanged)

public:
    explicit QtAndroidService(QObject *parent = 0);

    bool isSticky() const;
    void setSticky(bool sticky);

public Q_SLOTS:
    void start();
    void stop();

Q_SIGNALS:
    void stickyChanged();
    void started();
    void stopped();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject service);
    static void onCreated(JNIEnv *env, jobject object, jlong instance);
    static void onDestroyed(JNIEnv *env, jobject object, jlong instance);
    static jboolean onStartCommand(JNIEnv *env, jobject object, jlong instance, jint flags, jint startId);

private Q_SLOTS:
    bool startCommand(int flags, int startId);

private:
    bool m_sticky;
};

QT_END_NAMESPACE

#endif // QTANDROIDSERVICE_P_H
