#ifndef QTQMLANDROIDVIEWFLIPPER_P_H
#define QTQMLANDROIDVIEWFLIPPER_P_H

#include "qtqmlandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewFlipper : public QtQmlAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtQmlAndroidViewFlipper(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDVIEWFLIPPER_P_H
