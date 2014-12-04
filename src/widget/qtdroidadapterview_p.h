#ifndef QTDROIDADAPTERVIEW_P_H
#define QTDROIDADAPTERVIEW_P_H

#include "qtdroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtDroidBaseAdapter;

class QtDroidAdapterView : public QtDroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtDroidBaseAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QtDroidAdapterView(QtDroidView *parent = 0);

    QtDroidBaseAdapter *adapter() const;
    void setAdapter(QtDroidBaseAdapter *adapter);

public Q_SLOTS:
    void setSelection(int position);

Q_SIGNALS:
    void adapterChanged();
    void click(int position);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    static void registerNativeMethods(jobject listener);
    static void onItemClick(JNIEnv *env, jobject object, jlong instance, jint position);

private:
    QAndroidJniObject m_listener;
    QtDroidBaseAdapter *m_adapter;
};

QT_END_NAMESPACE

#endif // QTDROIDADAPTERVIEW_P_H
