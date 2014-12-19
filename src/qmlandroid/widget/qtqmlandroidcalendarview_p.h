#ifndef QTQMLANDROIDCALENDARVIEW_P_H
#define QTQMLANDROIDCALENDARVIEW_P_H

#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidCalendarView : public QtQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtQmlAndroidCalendarView(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCALENDARVIEW_P_H
