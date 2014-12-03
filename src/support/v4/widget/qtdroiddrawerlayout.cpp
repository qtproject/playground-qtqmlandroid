#include "qtdroiddrawerlayout_p.h"
#include "qtdroidactionbardrawertoggle_p.h"
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
    callVoidMethod("closeDrawers");
}

void QtDroidDrawerLayout::closeDrawer(int gravity)
{
    callIntMethod("closeDrawer", gravity);
}

QAndroidJniObject QtDroidDrawerLayout::construct(jobject context)
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidDrawerLayout::inflate(jobject context)
{
    QtDroidViewGroup::inflate(context);

    if (m_toggle)
        m_toggle->construct(context, instance().object());
}

void QtDroidDrawerLayout::childEvent(QChildEvent *event)
{
    QtDroidViewGroup::childEvent(event);

    // TODO: dynamic add/remove
    if (!m_toggle && event->added())
        m_toggle = qobject_cast<QtDroidActionBarDrawerToggle *>(event->child());
}
