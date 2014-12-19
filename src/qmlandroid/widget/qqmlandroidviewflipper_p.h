#ifndef QQMLANDROIDVIEWFLIPPER_P_H
#define QQMLANDROIDVIEWFLIPPER_P_H

#include "qqmlandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidViewFlipper : public QQmlAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QQmlAndroidViewFlipper(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDVIEWFLIPPER_P_H
