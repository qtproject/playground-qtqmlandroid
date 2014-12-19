#ifndef QTQMLANDROIDLINEARINTERPOLATOR_P_H
#define QTQMLANDROIDLINEARINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidLinearInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidLinearInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDLINEARINTERPOLATOR_P_H
