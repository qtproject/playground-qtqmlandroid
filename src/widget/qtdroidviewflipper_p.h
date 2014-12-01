#ifndef QTDROIDVIEWFLIPPER_P_H
#define QTDROIDVIEWFLIPPER_P_H

#include "qtdroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtDroidViewFlipper : public QtDroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtDroidViewFlipper(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDVIEWFLIPPER_P_H
