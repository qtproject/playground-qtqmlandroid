#ifndef QTQMLANDROIDBOUNCEINTERPOLATOR_P_H
#define QTQMLANDROIDBOUNCEINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"

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

#endif // QTQMLANDROIDBOUNCEINTERPOLATOR_P_H
