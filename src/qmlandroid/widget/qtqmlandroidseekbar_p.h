#ifndef QQMLANDROIDSEEKBAR_P_H
#define QQMLANDROIDSEEKBAR_P_H

#include "qtqmlandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidSeekBar : public QQmlAndroidAbsSeekBar
{
    Q_OBJECT

public:
    explicit QQmlAndroidSeekBar(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser);

private:
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSEEKBAR_P_H
