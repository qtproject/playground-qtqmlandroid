#ifndef QTQMLANDROIDRADIOGROUP_P_H
#define QTQMLANDROIDRADIOGROUP_P_H

#include "qtqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidRadioButton;

class QtQmlAndroidRadioGroup : public QtQmlAndroidLinearLayout
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidRadioButton *checkedButton READ checkedButton WRITE setCheckedButton NOTIFY checkedButtonChanged)

public:
    explicit QtQmlAndroidRadioGroup(QtQmlAndroidView *parent = 0);

    QtQmlAndroidRadioButton *checkedButton() const;
    void setCheckedButton(QtQmlAndroidRadioButton *button);

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
    bool updateCheckedButton(QtQmlAndroidRadioButton *button);

private:
    QAndroidJniObject m_listener;
    QtQmlAndroidRadioButton* m_checkedButton;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDRADIOGROUP_P_H
