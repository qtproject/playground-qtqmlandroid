#include "qtqmlandroiddrawerlayout_p.h"
#include "qtqmlandroidactionbardrawertoggle_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDrawerLayout::QtQmlAndroidDrawerLayout(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent)
{
}

QtQmlAndroidDrawerLayoutParams *QtQmlAndroidDrawerLayout::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidDrawerLayoutParams(view);
    return 0;
}

void QtQmlAndroidDrawerLayout::closeDrawers()
{
    QtQmlAndroid::callVoidMethod(instance(), "closeDrawers");
}

void QtQmlAndroidDrawerLayout::closeDrawer(int gravity)
{
    QtQmlAndroid::callIntMethod(instance(), "closeDrawer", gravity);
}

QAndroidJniObject QtQmlAndroidDrawerLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidDrawerLayout::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewGroup::onInflate(instance);

    foreach (QObject *child, QObject::children()) {
        QtQmlAndroidActionBarDrawerToggle *toggle = qobject_cast<QtQmlAndroidActionBarDrawerToggle *>(child);
        if (toggle)
            toggle->onCreate(ctx(), instance);
    }
}

QT_END_NAMESPACE
