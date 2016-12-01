#ifndef QQMLANDROIDRADIOGROUP_P_H
#define QQMLANDROIDRADIOGROUP_P_H

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

#include "qqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidRadioButton;

class QQmlAndroidRadioGroup : public QQmlAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidRadioButton *checkedButton READ checkedButton WRITE setCheckedButton NOTIFY checkedButtonChanged)

public:
    explicit QQmlAndroidRadioGroup(QQmlAndroidView *parent = 0);

    QQmlAndroidRadioButton *checkedButton() const;
    void setCheckedButton(QQmlAndroidRadioButton *button);

public Q_SLOTS:
    void clearCheck();

Q_SIGNALS:
    void checkedButtonChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId);

private Q_SLOTS:
    void updateCheckedButtonId(int checkedId);
    bool updateCheckedButton(QQmlAndroidRadioButton *button);

private:
    QAndroidJniObject m_listener;
    QQmlAndroidRadioButton* m_checkedButton;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRADIOGROUP_P_H
