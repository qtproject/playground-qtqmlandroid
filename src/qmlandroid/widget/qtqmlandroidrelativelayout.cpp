#include "qtqmlandroidrelativelayout_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRelativeLayout::QQmlAndroidRelativeLayout(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent)
{
}

QQmlAndroidRelativeLayoutParams *QQmlAndroidRelativeLayout::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidRelativeLayoutParams(view);
    return 0;
}

QAndroidJniObject QQmlAndroidRelativeLayout::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRelativeLayout::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
