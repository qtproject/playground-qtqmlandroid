#ifndef QTANDROIDTIMEPICKER_P_H
#define QTANDROIDTIMEPICKER_P_H

#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidTimePicker : public QtAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtAndroidTimePicker(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDTIMEPICKER_P_H
