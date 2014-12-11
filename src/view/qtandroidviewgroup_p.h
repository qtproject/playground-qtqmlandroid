#ifndef QTANDROIDVIEWGROUP_P_H
#define QTANDROIDVIEWGROUP_P_H

#include "qtandroidview_p.h"
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtAndroidViewGroup : public QtAndroidView
{
    Q_OBJECT

public:
    explicit QtAndroidViewGroup(QtAndroidView *parent = 0);

    static QtAndroidLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    void viewChange(ViewChange change, const ViewChangeData &data) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidViewGroup, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDVIEWGROUP_P_H
