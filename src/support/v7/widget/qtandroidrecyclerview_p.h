#ifndef QTANDROIDRECYCLERVIEW_P_H
#define QTANDROIDRECYCLERVIEW_P_H

#include "qtandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRecyclerAdapter;

class QtAndroidRecyclerView : public QtAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidRecyclerAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged)

public:
    explicit QtAndroidRecyclerView(QtAndroidView *parent = 0);

    QtAndroidRecyclerAdapter *adapter() const;
    void setAdapter(QtAndroidRecyclerAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateAdapter();

private:
    QtAndroidRecyclerAdapter *m_adapter;
    QAndroidJniObject m_layoutManager;
};

QT_END_NAMESPACE

#endif // QTANDROIDRECYCLERVIEW_P_H
