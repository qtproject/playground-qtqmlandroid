#ifndef QTANDROIDINTERPOLATOR_P_H
#define QTANDROIDINTERPOLATOR_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidInterpolator : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDINTERPOLATOR_P_H
