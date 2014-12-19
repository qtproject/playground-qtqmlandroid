#ifndef QTQMLANDROIDADAPTERVIEW_P_H
#define QTQMLANDROIDADAPTERVIEW_P_H

#include "qtqmlandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidBaseAdapter;

class QtQmlAndroidAdapterView : public QtQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidBaseAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QtQmlAndroidAdapterView(QtQmlAndroidView *parent = 0);

    QtQmlAndroidBaseAdapter *adapter() const;
    void setAdapter(QtQmlAndroidBaseAdapter *adapter);

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
    QtQmlAndroidBaseAdapter *m_adapter;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDADAPTERVIEW_P_H
