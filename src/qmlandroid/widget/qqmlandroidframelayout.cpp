#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidFrameLayout::QQmlAndroidFrameLayout(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent)
{
}

QQmlAndroidFrameLayoutParams *QQmlAndroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QQmlAndroidFrameLayout::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidFrameLayout::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
