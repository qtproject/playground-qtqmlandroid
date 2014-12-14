#ifndef QTANDROIDTABHOST_P_H
#define QTANDROIDTABHOST_P_H

#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidTabHost : public QtAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtAndroidTabHost(QtAndroidView *parent = 0);

Q_SIGNALS:
    void tabChanged(const QString &tabId);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId);

private:
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDTABHOST_P_H
