#ifndef QTANDROIDVIEWFLIPPER_P_H
#define QTANDROIDVIEWFLIPPER_P_H

#include "qtandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidViewFlipper : public QtAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtAndroidViewFlipper(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDVIEWFLIPPER_P_H