#ifndef QTQMLANDROIDINTERPOLATOR_P_H
#define QTQMLANDROIDINTERPOLATOR_P_H

#include "qtqmlandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidInterpolator : public QQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QQmlAndroidInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDINTERPOLATOR_P_H
