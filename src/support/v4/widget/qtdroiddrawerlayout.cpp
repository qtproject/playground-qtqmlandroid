#include "qtdroiddrawerlayout_p.h"
#include "qtdroidactionbardrawertoggle_p.h"
#include "qtdroidfunctions_p.h"
#include <QtCore/qcoreevent.h>

QtDroidDrawerLayout::QtDroidDrawerLayout(QtDroidView *parent) :
    QtDroidViewGroup(parent), m_toggle(0)
{
}

QtDroidDrawerLayoutParams *QtDroidDrawerLayout::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidDrawerLayoutParams(view);
    return 0;
}

void QtDroidDrawerLayout::closeDrawers()
{
    QtDroid::callVoidMethod(instance(), "closeDrawers");
}

void QtDroidDrawerLayout::closeDrawer(int gravity)
{
    QtDroid::callIntMethod(instance(), "closeDrawer", gravity);
}

QAndroidJniObject QtDroidDrawerLayout::construct()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidDrawerLayout::inflate()
{
    QtDroidViewGroup::inflate();

    if (m_toggle)
        m_toggle->construct(ctx().object(), instance().object());
}

void QtDroidDrawerLayout::childEvent(QChildEvent *event)
{
    QtDroidViewGroup::childEvent(event);

    // TODO: dynamic add/remove
    if (!m_toggle && event->added())
        m_toggle = qobject_cast<QtDroidActionBarDrawerToggle *>(event->child());
}
