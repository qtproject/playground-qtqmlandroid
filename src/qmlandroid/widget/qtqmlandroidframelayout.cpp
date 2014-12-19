#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidFrameLayout::QtQmlAndroidFrameLayout(QtQmlAndroidView *parent) :
    QtQmlAndroidViewGroup(parent)
{
}

QtQmlAndroidFrameLayoutParams *QtQmlAndroidFrameLayout::qmlAttachedProperties(QObject *object)
{
    QtQmlAndroidView *view = qobject_cast<QtQmlAndroidView*>(object);
    if (view)
        return new QtQmlAndroidFrameLayoutParams(view);
    return 0;
}

QAndroidJniObject QtQmlAndroidFrameLayout::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidFrameLayout::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidViewGroup::onInflate(instance);
}

QT_END_NAMESPACE
