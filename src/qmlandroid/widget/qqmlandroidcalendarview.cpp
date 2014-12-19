#include "qqmlandroidcalendarview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidCalendarView::QQmlAndroidCalendarView(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QQmlAndroidCalendarView::onCreate()
{
    return QAndroidJniObject("android/widget/CalendarView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidCalendarView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
