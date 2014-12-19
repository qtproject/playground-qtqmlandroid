#ifndef QQMLANDROIDINTERPOLATOR_P_H
#define QQMLANDROIDINTERPOLATOR_P_H

#include "qqmlandroidobject_p.h"

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

#endif // QQMLANDROIDINTERPOLATOR_P_H
