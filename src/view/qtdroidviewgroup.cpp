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

QQmlListProperty<QtDroidView> QtDroidViewGroup::children()
{
    return QQmlListProperty<QtDroidView>(this, 0, &QtDroidViewGroup::children_append, &QtDroidViewGroup::children_count,
                                                   &QtDroidViewGroup::children_at, &QtDroidViewGroup::children_clear);
}

void QtDroidViewGroup::objectAdded(QObject *object)
{
    QtDroidView *child = qobject_cast<QtDroidView *>(object);
    if (child) {
        child->setContext(context());
        m_children.append(child);
        emit childrenChanged();
    }
}

void QtDroidViewGroup::objectRemoved(QObject *object)
{
    QtDroidView *child = qobject_cast<QtDroidView *>(object);
    if (child) {
        if (m_children.removeOne(child)) {
            child->setContext(0);
            emit childrenChanged();
        }
    }
}

void QtDroidViewGroup::children_append(QQmlListProperty<QtDroidView> *list, QtDroidView *child)
{
    if (QtDroidViewGroup *that = qobject_cast<QtDroidViewGroup *>(list->object)) {
        that->m_children.append(child);
        emit that->childrenChanged();
    }
}

int QtDroidViewGroup::children_count(QQmlListProperty<QtDroidView> *list)
{
    if (QtDroidViewGroup *that = qobject_cast<QtDroidViewGroup *>(list->object))
        return that->m_children.count();
    return 0;
}

QtDroidView *QtDroidViewGroup::children_at(QQmlListProperty<QtDroidView> *list, int index)
{
    if (QtDroidViewGroup *that = qobject_cast<QtDroidViewGroup *>(list->object))
        return that->m_children.at(index);
    return 0;
}

void QtDroidViewGroup::children_clear(QQmlListProperty<QtDroidView> *list)
{
    if (QtDroidViewGroup *that = qobject_cast<QtDroidViewGroup *>(list->object)) {
        if (!that->m_children.isEmpty()) {
            that->m_children.clear();
            emit that->childrenChanged();
        }
    }
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
