#ifndef QTQMLANDROIDVIEWGROUP_P_H
#define QTQMLANDROIDVIEWGROUP_P_H

#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewGroup : public QtQmlAndroidView
{
    Q_OBJECT

public:
    explicit QtQmlAndroidViewGroup(QtQmlAndroidView *parent = 0);

    static QtQmlAndroidLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    void viewChange(ViewChange change, const ViewChangeData &data) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtQmlAndroidViewGroup, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTQMLANDROIDVIEWGROUP_P_H
