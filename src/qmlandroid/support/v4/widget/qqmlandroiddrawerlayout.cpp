#include "qqmlandroiddrawerlayout_p.h"
#include "qqmlandroidactionbardrawertoggle_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDrawerLayout::QQmlAndroidDrawerLayout(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent)
{
}

QQmlAndroidDrawerLayoutParams *QQmlAndroidDrawerLayout::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidDrawerLayoutParams(view);
    return 0;
}

void QQmlAndroidDrawerLayout::closeDrawers()
{
    QtQmlAndroid::callVoidMethod(instance(), "closeDrawers");
}

void QQmlAndroidDrawerLayout::closeDrawer(int gravity)
{
    QtQmlAndroid::callIntMethod(instance(), "closeDrawer", gravity);
}

QAndroidJniObject QQmlAndroidDrawerLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidDrawerLayout::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewGroup::onInflate(instance);

    foreach (QObject *child, QObject::children()) {
        QQmlAndroidActionBarDrawerToggle *toggle = qobject_cast<QQmlAndroidActionBarDrawerToggle *>(child);
        if (toggle)
            toggle->onCreate(ctx(), instance);
    }
}

QT_END_NAMESPACE
