#ifndef QTDROIDCALENDARVIEW_P_H
#define QTDROIDCALENDARVIEW_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidCalendarView : public QtDroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtDroidCalendarView(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDCALENDARVIEW_P_H
