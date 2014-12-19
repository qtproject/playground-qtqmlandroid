#ifndef QTQMLANDROIDVIEWSWITCHER_P_H
#define QTQMLANDROIDVIEWSWITCHER_P_H

#include "qtqmlandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewSwitcher : public QtQmlAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QtQmlAndroidViewSwitcher(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDVIEWSWITCHER_P_H
