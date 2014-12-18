#ifndef QTANDROIDLINEARINTERPOLATOR_P_H
#define QTANDROIDLINEARINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidLinearInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtAndroidLinearInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDLINEARINTERPOLATOR_P_H
