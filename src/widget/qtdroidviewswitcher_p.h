#ifndef QTDROIDVIEWSWITCHER_P_H
#define QTDROIDVIEWSWITCHER_P_H

#include "qtdroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtDroidViewSwitcher : public QtDroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtDroidViewSwitcher(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDVIEWSWITCHER_P_H
