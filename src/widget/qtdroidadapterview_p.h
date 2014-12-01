#ifndef QTDROIDADAPTERVIEW_P_H
#define QTDROIDADAPTERVIEW_P_H

#include "qtdroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtDroidArrayAdapter;

class QtDroidAdapterView : public QtDroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtDroidArrayAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QtDroidAdapterView(QObject *parent = 0);

    QtDroidArrayAdapter *adapter() const;
    void setAdapter(QtDroidArrayAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();
    void click(int position);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onItemClick(JNIEnv *env, jobject object, jlong instance, jint position);

private:
    QAndroidJniObject m_listener;
    QtDroidArrayAdapter *m_adapter;
};

QT_END_NAMESPACE

#endif // QTDROIDADAPTERVIEW_P_H
