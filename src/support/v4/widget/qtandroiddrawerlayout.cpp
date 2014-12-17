#include "qtandroiddrawerlayout_p.h"
#include "qtandroidactionbardrawertoggle_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidDrawerLayout::QtAndroidDrawerLayout(QtAndroidView *parent) :
    QtAndroidViewGroup(parent)
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

QAndroidJniObject QtAndroidDrawerLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidDrawerLayout::onInflate(QAndroidJniObject &instance)
{
    QtAndroidViewGroup::onInflate(instance);

    foreach (QObject *child, QObject::children()) {
        QtAndroidActionBarDrawerToggle *toggle = qobject_cast<QtAndroidActionBarDrawerToggle *>(child);
        if (toggle)
            toggle->onCreate(ctx(), instance);
    }
}

QT_END_NAMESPACE
