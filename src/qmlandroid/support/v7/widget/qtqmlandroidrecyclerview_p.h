#ifndef QTQMLANDROIDRECYCLERVIEW_P_H
#define QTQMLANDROIDRECYCLERVIEW_P_H

#include "qtqmlandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidRecyclerAdapter;

class QtQmlAndroidRecyclerView : public QtQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidRecyclerAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged)

public:
    explicit QtQmlAndroidRecyclerView(QtQmlAndroidView *parent = 0);

    QtQmlAndroidRecyclerAdapter *adapter() const;
    void setAdapter(QtQmlAndroidRecyclerAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateAdapter();

private:
    QtQmlAndroidRecyclerAdapter *m_adapter;
    QAndroidJniObject m_layoutManager;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDRECYCLERVIEW_P_H
