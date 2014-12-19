#include "qtqmlandroidrecyclerview_p.h"
#include "qtqmlandroidrecycleradapter_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRecyclerView::QQmlAndroidRecyclerView(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent), m_adapter(0)
{
}

QQmlAndroidRecyclerAdapter *QQmlAndroidRecyclerView::adapter() const
{
    return m_adapter;
}

void QQmlAndroidRecyclerView::setAdapter(QQmlAndroidRecyclerAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidRecyclerView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidRecyclerView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }}

QAndroidJniObject QQmlAndroidRecyclerView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/RecyclerView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRecyclerView::onInflate(QAndroidJniObject& instance)
{
    m_layoutManager = QAndroidJniObject("android/support/v7/widget/LinearLayoutManager",
                                        "(Landroid/content/Context;)V",
                                        ctx().object());

    instance.callMethod<void>("setLayoutManager",
                              "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                              m_layoutManager.object());

    QQmlAndroidViewGroup::onInflate(instance);
}

void QQmlAndroidRecyclerView::objectChange(ObjectChange change)
{
    QQmlAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QQmlAndroidRecyclerView::updateAdapter()
{
    if (!isValid() || !m_adapter)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject adapter = m_adapter->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/support/v7/widget/RecyclerView$Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
