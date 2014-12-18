#ifndef QTANDROIDRADIOGROUP_P_H
#define QTANDROIDRADIOGROUP_P_H

#include "qtandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRadioButton;

class QtAndroidRadioGroup : public QtAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidRadioButton *checkedButton READ checkedButton WRITE setCheckedButton NOTIFY checkedButtonChanged)

public:
    explicit QtAndroidRadioGroup(QtAndroidView *parent = 0);

    QtAndroidRadioButton *checkedButton() const;
    void setCheckedButton(QtAndroidRadioButton *button);

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
    bool updateCheckedButton(QtAndroidRadioButton *button);

private:
    QAndroidJniObject m_listener;
    QtAndroidRadioButton* m_checkedButton;
};

QT_END_NAMESPACE

#endif // QTANDROIDRADIOGROUP_P_H
