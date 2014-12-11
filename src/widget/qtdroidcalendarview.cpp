#include "qtdroidcalendarview_p.h"

QtAndroidCalendarView::QtAndroidCalendarView(QtAndroidView *parent) : QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidCalendarView::construct()
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCalendarView::inflate()
{
    QtAndroidViewGroup::inflate();
}
