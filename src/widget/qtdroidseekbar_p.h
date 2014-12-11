#ifndef QTDROIDSEEKBAR_P_H
#define QTDROIDSEEKBAR_P_H

#include "qtdroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSeekBar : public QtAndroidAbsSeekBar
{
    Q_OBJECT

public:
    explicit QtAndroidSeekBar(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser);

private:
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTDROIDSEEKBAR_P_H
