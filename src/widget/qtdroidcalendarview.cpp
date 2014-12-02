#include "qtdroidcalendarview_p.h"

QtDroidCalendarView::QtDroidCalendarView(QObject *parent) : QtDroidFrameLayout(parent)
{
}

QAndroidJniObject QtDroidCalendarView::construct(jobject context)
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidCalendarView::inflate(jobject context)
{
    QtDroidViewGroup::inflate(context);
}
