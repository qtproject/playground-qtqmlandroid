#ifndef QTANDROIDBOUNCEINTERPOLATOR_P_H
#define QTANDROIDBOUNCEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidBounceInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtAndroidBounceInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDBOUNCEINTERPOLATOR_P_H
