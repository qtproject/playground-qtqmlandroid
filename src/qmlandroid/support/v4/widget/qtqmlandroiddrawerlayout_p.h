#ifndef QTQMLANDROIDDRAWERLAYOUT_P_H
#define QTQMLANDROIDDRAWERLAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroiddrawerlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidDrawerLayout : public QtQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QtQmlAndroidDrawerLayout(QtQmlAndroidView *parent = 0);

    static QtQmlAndroidDrawerLayoutParams *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    void closeDrawers();
    void closeDrawer(int gravity);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtQmlAndroidDrawerLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTQMLANDROIDDRAWERLAYOUT_P_H
