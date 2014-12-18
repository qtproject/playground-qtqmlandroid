#ifndef QTANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
#define QTANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAccelerateDecelerateInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtAndroidAccelerateDecelerateInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
