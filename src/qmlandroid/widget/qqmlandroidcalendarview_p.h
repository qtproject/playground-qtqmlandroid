#ifndef QQMLANDROIDCALENDARVIEW_P_H
#define QQMLANDROIDCALENDARVIEW_P_H

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidCalendarView : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidCalendarView(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCALENDARVIEW_P_H
