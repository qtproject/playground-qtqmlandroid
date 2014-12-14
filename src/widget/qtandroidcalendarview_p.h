#ifndef QTANDROIDCALENDARVIEW_P_H
#define QTANDROIDCALENDARVIEW_P_H

#include "qtandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidCalendarView : public QtAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtAndroidCalendarView(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDCALENDARVIEW_P_H
