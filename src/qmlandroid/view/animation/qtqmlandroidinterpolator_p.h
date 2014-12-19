#ifndef QTQMLANDROIDINTERPOLATOR_P_H
#define QTQMLANDROIDINTERPOLATOR_P_H

#include "qtqmlandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidInterpolator : public QtQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QtQmlAndroidInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDINTERPOLATOR_P_H
