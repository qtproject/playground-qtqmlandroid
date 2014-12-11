#ifndef QTDROIDCALENDARVIEW_P_H
#define QTDROIDCALENDARVIEW_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidCalendarView : public QtAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtAndroidCalendarView(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDCALENDARVIEW_P_H
