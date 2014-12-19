#ifndef QQMLANDROIDBOUNCEINTERPOLATOR_P_H
#define QQMLANDROIDBOUNCEINTERPOLATOR_P_H

#include "qqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidBounceInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidBounceInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDBOUNCEINTERPOLATOR_P_H
