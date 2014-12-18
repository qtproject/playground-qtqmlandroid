#ifndef QTANDROIDSPACE_P_H
#define QTANDROIDSPACE_P_H

#include "qtandroidview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSpace : public QtAndroidView
{
    Q_OBJECT

public:
    explicit QtAndroidSpace(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDSPACE_P_H
