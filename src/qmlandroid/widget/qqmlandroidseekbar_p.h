#ifndef QQMLANDROIDSEEKBAR_P_H
#define QQMLANDROIDSEEKBAR_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidabsseekbar_p.h"

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
