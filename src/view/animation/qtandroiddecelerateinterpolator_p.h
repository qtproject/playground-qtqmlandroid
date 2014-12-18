#ifndef QTANDROIDDECELERATEINTERPOLATOR_P_H
#define QTANDROIDDECELERATEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDecelerateInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QtAndroidDecelerateInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDDECELERATEINTERPOLATOR_P_H
