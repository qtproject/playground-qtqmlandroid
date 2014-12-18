#include "qtandroidcalendarview_p.h"

QT_BEGIN_NAMESPACE

QtAndroidCalendarView::QtAndroidCalendarView(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
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

QT_END_NAMESPACE
