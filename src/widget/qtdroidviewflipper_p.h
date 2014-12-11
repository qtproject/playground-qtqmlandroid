#ifndef QTDROIDVIEWFLIPPER_P_H
#define QTDROIDVIEWFLIPPER_P_H

#include "qtdroidviewanimator_p.h"

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

#endif // QTDROIDVIEWFLIPPER_P_H
