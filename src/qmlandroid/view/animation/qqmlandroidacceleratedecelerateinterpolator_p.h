#ifndef QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
#define QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H

#include "qqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidAccelerateDecelerateInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidAccelerateDecelerateInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
