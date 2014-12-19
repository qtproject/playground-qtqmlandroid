#ifndef QQMLANDROIDVIEWSWITCHER_P_H
#define QQMLANDROIDVIEWSWITCHER_P_H

#include "qqmlandroidviewanimator_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidViewSwitcher : public QQmlAndroidViewAnimator
{
    Q_OBJECT

public:
    explicit QQmlAndroidViewSwitcher(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDVIEWSWITCHER_P_H
