#include "qtdroidviewgroup_p.h"
#include "qtdroidlayoutparams_p.h"
#include "qtdroidcontext_p.h"

QtDroidViewGroup::QtDroidViewGroup(QObject *parent) : QtDroidView(parent)
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
