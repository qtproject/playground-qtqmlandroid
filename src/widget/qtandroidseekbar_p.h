#ifndef QTANDROIDSEEKBAR_P_H
#define QTANDROIDSEEKBAR_P_H

#include "qtandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSeekBar : public QtAndroidAbsSeekBar
{
    Q_OBJECT

public:
    explicit QtAndroidSeekBar(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser);

private:
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDSEEKBAR_P_H
