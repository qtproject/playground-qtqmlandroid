#ifndef QTQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
#define QTQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidAccelerateDecelerateInterpolator : public QtQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtQmlAndroidAccelerateDecelerateInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
