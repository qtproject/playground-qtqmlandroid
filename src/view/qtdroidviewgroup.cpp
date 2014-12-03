#include "qtdroidviewgroup_p.h"
#include "qtdroidlayoutparams_p.h"
#include "qtdroidfunctions_p.h"
#include "qtdroidcontext_p.h"

QtDroidViewGroup::QtDroidViewGroup(QtDroidView *parent) : QtDroidView(parent)
{
}

QtDroidLayoutParams *QtDroidViewGroup::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidLayoutParams(view);
    return 0;
}

QAndroidJniObject QtDroidViewGroup::construct(jobject context)
{
    return QAndroidJniObject("android/view/ViewGroup",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidViewGroup::inflate(jobject context)
{
    QtDroidView::inflate(context);

    foreach (QtDroidView *child, m_children) {
        child->setInstance(child->construct(context));
        child->inflate(context);
        instance().callMethod<void>("addView", "(Landroid/view/View;)V", child->instance().object());
    }
}

void QtDroidViewGroup::viewChange(ViewChange change, const ViewChangeData &data)
{
    QAndroidJniObject group = instance();
    switch (change) {
    case ViewChildAddedChange: // data.view
        if (group.isValid()) {
            QAndroidJniObject ctx = context()->instance();
            QtDroid::callFunction([=]() {
                QAndroidJniObject child = data.view->construct(ctx.object());
                data.view->setInstance(child);
                data.view->inflate(ctx.object());
                group.callMethod<void>("addView", "(Landroid/view/View;)V", child.object());
            });
        }
        break;
    case ViewChildRemovedChange: // data.view
        if (group.isValid()) {
            QAndroidJniObject child = data.view->instance();
            QtDroid::callFunction([=]() {
                group.callMethod<void>("removeView", "(Landroid/view/View;)V", child.object());
            });
            data.view->setInstance(QAndroidJniObject());
        }
        break;
    default:
        break;
    }
}
