#ifndef QTANDROIDRECYCLERVIEW_P_H
#define QTANDROIDRECYCLERVIEW_P_H

#include "qtandroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidBaseAdapter;

class QtAndroidRecyclerView : public QtAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidBaseAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged) // TODO: Adapter

public:
    explicit QtAndroidRecyclerView(QtAndroidView *parent = 0);

    QtAndroidBaseAdapter *adapter() const;
    void setAdapter(QtAndroidBaseAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

private:
    QtAndroidBaseAdapter *m_adapter;
    QAndroidJniObject m_layoutManager;
};

QT_END_NAMESPACE

#endif // QTANDROIDRECYCLERVIEW_P_H
