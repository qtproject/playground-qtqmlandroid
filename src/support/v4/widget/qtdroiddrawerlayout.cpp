#include "qtdroiddrawerlayout_p.h"
#include "qtdroidactionbardrawertoggle_p.h"

QtDroidDrawerLayout::QtDroidDrawerLayout(QObject *parent) : QtDroidViewGroup(parent), m_toggle(0)
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
    QtDroidObject::callUiMethod([=]() {
        instance().callMethod<void>("closeDrawers");
    });
}

void QtDroidDrawerLayout::closeDrawer(int gravity)
{
    QtDroidObject::callUiMethod([=]() {
        instance().callMethod<void>("closeDrawer", "(I)V", gravity);
    });
}

void QtDroidDrawerLayout::objectAdded(QObject *object)
{
    QtDroidViewGroup::objectAdded(object);

    if (!m_toggle)
        m_toggle = qobject_cast<QtDroidActionBarDrawerToggle *>(object);
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
