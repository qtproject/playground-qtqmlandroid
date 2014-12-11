#ifndef QTDROIDRADIOGROUP_P_H
#define QTDROIDRADIOGROUP_P_H

#include "qtdroidlinearlayout_p.h"

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
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId);

private Q_SLOTS:
    void updateCheckedButtonId(int checkedId);
    bool updateCheckedButton(QtAndroidRadioButton *button);

private:
    QAndroidJniObject m_listener;
    QtAndroidRadioButton* m_checkedButton;
};

QT_END_NAMESPACE

#endif // QTDROIDRADIOGROUP_P_H
