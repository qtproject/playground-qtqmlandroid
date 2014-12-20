#ifndef QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
#define QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H

#include "qtqmlandroidglobal_p.h"
#include "qqmlandroidoptional_p.h"
#include "qqmlandroidinterpolator_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidAccelerateDecelerateInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidAccelerateDecelerateInterpolator(QObject *parent = 0);

Q_SIGNALS:

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
