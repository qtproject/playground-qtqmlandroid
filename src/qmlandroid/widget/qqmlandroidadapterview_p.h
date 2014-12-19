#ifndef QQMLANDROIDADAPTERVIEW_P_H
#define QQMLANDROIDADAPTERVIEW_P_H

#include "qqmlandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidBaseAdapter;

class QQmlAndroidAdapterView : public QQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidBaseAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QQmlAndroidAdapterView(QQmlAndroidView *parent = 0);

    QQmlAndroidBaseAdapter *adapter() const;
    void setAdapter(QQmlAndroidBaseAdapter *adapter);

public Q_SLOTS:
    void setSelection(int position);

Q_SIGNALS:
    void adapterChanged();
    void click(int position);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onItemClick(JNIEnv *env, jobject object, jlong instance, jint position);

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateAdapter();

private:
    QAndroidJniObject m_listener;
    QQmlAndroidBaseAdapter *m_adapter;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDADAPTERVIEW_P_H
