#ifndef QQMLANDROIDRECYCLERVIEW_P_H
#define QQMLANDROIDRECYCLERVIEW_P_H

#include "qtqmlandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidRecyclerAdapter;

class QQmlAndroidRecyclerView : public QQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidRecyclerAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged)

public:
    explicit QQmlAndroidRecyclerView(QQmlAndroidView *parent = 0);

    QQmlAndroidRecyclerAdapter *adapter() const;
    void setAdapter(QQmlAndroidRecyclerAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateAdapter();

private:
    QQmlAndroidRecyclerAdapter *m_adapter;
    QAndroidJniObject m_layoutManager;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRECYCLERVIEW_P_H
