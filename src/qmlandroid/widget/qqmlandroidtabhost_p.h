#ifndef QQMLANDROIDTABHOST_P_H
#define QQMLANDROIDTABHOST_P_H

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidTabHost : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidTabHost(QQmlAndroidView *parent = 0);

Q_SIGNALS:
    void tabChanged(const QString &tabId);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId);

private:
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTABHOST_P_H
