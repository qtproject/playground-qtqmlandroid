#ifndef QQMLANDROIDLINEARINTERPOLATOR_P_H
#define QQMLANDROIDLINEARINTERPOLATOR_P_H

#include "qtqmlandroidglobal_p.h"
#include "qqmlandroidoptional_p.h"
#include "qqmlandroidinterpolator_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidLinearInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidLinearInterpolator(QObject *parent = 0);

Q_SIGNALS:

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
};

QT_END_NAMESPACE

#endif // QQMLANDROIDLINEARINTERPOLATOR_P_H
