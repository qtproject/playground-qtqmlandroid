#include "qtdroiddrawerlayout_p.h"
#include "qtdroidactionbardrawertoggle_p.h"
#include "qtdroidfunctions_p.h"
#include <QtCore/qcoreevent.h>

QtAndroidDrawerLayout::QtAndroidDrawerLayout(QtAndroidView *parent) :
    QtAndroidViewGroup(parent), m_toggle(0)
{
}

QtAndroidDrawerLayoutParams *QtAndroidDrawerLayout::qmlAttachedProperties(QObject *object)
{
    QtAndroidView *view = qobject_cast<QtAndroidView*>(object);
    if (view)
        return new QtAndroidDrawerLayoutParams(view);
    return 0;
}

void QtAndroidDrawerLayout::closeDrawers()
{
    QtAndroid::callVoidMethod(instance(), "closeDrawers");
}

void QtAndroidDrawerLayout::closeDrawer(int gravity)
{
    QtAndroid::callIntMethod(instance(), "closeDrawer", gravity);
}

QAndroidJniObject QtAndroidDrawerLayout::construct()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidDrawerLayout::inflate()
{
    QtAndroidViewGroup::inflate();

    if (m_toggle)
        m_toggle->construct(ctx().object(), instance().object());
}

void QtAndroidDrawerLayout::childEvent(QChildEvent *event)
{
    QtAndroidViewGroup::childEvent(event);

    // TODO: dynamic add/remove
    if (!m_toggle && event->added())
        m_toggle = qobject_cast<QtAndroidActionBarDrawerToggle *>(event->child());
}
