#ifndef QTQMLANDROIDBOUNCEINTERPOLATOR_P_H
#define QTQMLANDROIDBOUNCEINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidBounceInterpolator : public QtQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtQmlAndroidBounceInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDBOUNCEINTERPOLATOR_P_H
