#ifndef QTDROIDCALENDARVIEW_P_H
#define QTDROIDCALENDARVIEW_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidCalendarView : public QtDroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtDroidCalendarView(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDCALENDARVIEW_P_H
