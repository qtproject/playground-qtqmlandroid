#ifndef QTANDROIDDRAWABLE_P_H
#define QTANDROIDDRAWABLE_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDrawable : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidDrawable(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDDRAWABLE_P_H
