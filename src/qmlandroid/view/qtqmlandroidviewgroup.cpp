#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidlayoutparams_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qtqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidViewGroup::QQmlAndroidViewGroup(QQmlAndroidView *parent) :
    QQmlAndroidView(parent)
{
}

QQmlAndroidLayoutParams *QQmlAndroidViewGroup::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidLayoutParams(view);
    return 0;
}

QAndroidJniObject QQmlAndroidViewGroup::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidViewGroup::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);

    foreach (QQmlAndroidView *child, childViews())
        instance.callMethod<void>("addView", "(Landroid/view/View;)V", child->instance().object());
}

void QQmlAndroidViewGroup::viewChange(ViewChange change, const ViewChangeData &data)
{
    QAndroidJniObject group = instance();
    switch (change) {
    case ViewChildAddedChange: // data.view
        if (group.isValid()) {
//            QtQmlAndroid::callFunction([=]() {
//                QAndroidJniObject child = data.view->onCreate();
//                data.view->onInflate(child);
//                data.view->setInstance(child);
//                group.callMethod<void>("addView", "(Landroid/view/View;)V", child.object());
//            });
        }
        break;
    case ViewChildRemovedChange: // data.view
        if (group.isValid()) {
//            QAndroidJniObject child = data.view->instance();
//            QtQmlAndroid::callFunction([=]() {
//                group.callMethod<void>("removeView", "(Landroid/view/View;)V", child.object());
//            });
//            data.view->setInstance(QAndroidJniObject());
        }
        break;
    default:
        break;
    }
}

QT_END_NAMESPACE
