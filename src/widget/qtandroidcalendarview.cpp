#include "qtandroidcalendarview_p.h"

QtAndroidCalendarView::QtAndroidCalendarView(QtAndroidView *parent) : QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidCalendarView::onCreate()
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCalendarView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewGroup::onInflate(instance);
}
