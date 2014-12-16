#ifndef QTANDROIDDATEPICKER_P_H
#define QTANDROIDDATEPICKER_P_H

#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDatePicker : public QtAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtAndroidDatePicker(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDDATEPICKER_P_H
