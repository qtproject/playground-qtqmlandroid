#include "qtqmlandroidrelativelayout_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidRelativeLayout::QtQmlAndroidRelativeLayout(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent)
{
}

QtQmlAndroidRelativeLayoutParams *QtQmlAndroidRelativeLayout::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidRelativeLayoutParams(view);
    return 0;
}

QAndroidJniObject QtQmlAndroidRelativeLayout::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidRelativeLayout::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
