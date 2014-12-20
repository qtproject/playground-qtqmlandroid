#ifndef QQMLANDROIDBOUNCEINTERPOLATOR_P_H
#define QQMLANDROIDBOUNCEINTERPOLATOR_P_H

#include "qtqmlandroidglobal_p.h"
#include "qqmlandroidoptional_p.h"
#include "qqmlandroidinterpolator_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidBounceInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidBounceInterpolator(QObject *parent = 0);

Q_SIGNALS:

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
};

QT_END_NAMESPACE

#endif // QQMLANDROIDBOUNCEINTERPOLATOR_P_H
