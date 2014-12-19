#ifndef QTQMLANDROIDLINEARINTERPOLATOR_P_H
#define QTQMLANDROIDLINEARINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidLinearInterpolator : public QtQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtQmlAndroidLinearInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDLINEARINTERPOLATOR_P_H
