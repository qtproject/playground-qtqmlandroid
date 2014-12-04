#include "qtdroidcalendarview_p.h"

QtDroidCalendarView::QtDroidCalendarView(QtDroidView *parent) : QtDroidFrameLayout(parent)
{
}

QAndroidJniObject QtDroidCalendarView::construct()
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidCalendarView::inflate()
{
    QtDroidViewGroup::inflate();
}
