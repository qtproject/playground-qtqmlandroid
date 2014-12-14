#ifndef QTANDROIDCOMPOUNDBUTTON_P_H
#define QTANDROIDCOMPOUNDBUTTON_P_H

#include "qtandroidbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidCompoundButton : public QtAndroidButton
{
    Q_OBJECT
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY checkedChanged)

public:
    explicit QtAndroidCompoundButton(QtAndroidView *parent = 0);

    bool isChecked() const;
    void setChecked(bool checked);

public Q_SLOTS:
    void toggle();

Q_SIGNALS:
    void checkedChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jboolean isChecked);

private Q_SLOTS:
    bool updateChecked(bool checked);

private:
    bool m_checked;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDCOMPOUNDBUTTON_P_H
