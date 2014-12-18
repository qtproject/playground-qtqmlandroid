#ifndef QTANDROIDACCELERATEINTERPOLATOR_P_H
#define QTANDROIDACCELERATEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAccelerateInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtAndroidAccelerateInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDACCELERATEINTERPOLATOR_P_H
