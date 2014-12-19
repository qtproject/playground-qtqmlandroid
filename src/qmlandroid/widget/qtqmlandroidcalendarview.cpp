#include "qtqmlandroidcalendarview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidCalendarView::QtQmlAndroidCalendarView(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidCalendarView::onCreate()
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidCalendarView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
