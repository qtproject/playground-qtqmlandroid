#ifndef QTANDROIDVIEWSWITCHER_P_H
#define QTANDROIDVIEWSWITCHER_P_H

#include "qtandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidViewSwitcher : public QtAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtAndroidViewSwitcher(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDVIEWSWITCHER_P_H
