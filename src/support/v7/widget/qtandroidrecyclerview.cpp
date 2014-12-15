#include "qtandroidrecyclerview_p.h"
#include "qtandroidrecycleradapter_p.h"
#include "qtandroidfunctions_p.h"

QtAndroidRecyclerView::QtAndroidRecyclerView(QtAndroidView *parent) :
    QtAndroidViewGroup(parent), m_adapter(0)
{
    connect(this, SIGNAL(instanceChanged()), this, SLOT(updateAdapter()));
}

QtAndroidRecyclerAdapter *QtAndroidRecyclerView::adapter() const
{
    return m_adapter;
}

void QtAndroidRecyclerView::setAdapter(QtAndroidRecyclerAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, SIGNAL(instanceChanged()), this, SLOT(updateAdapter()));
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, SIGNAL(instanceChanged()), this, SLOT(updateAdapter()));
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }}

QAndroidJniObject QtAndroidRecyclerView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/RecyclerView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRecyclerView::onInflate(QAndroidJniObject& instance)
{
    m_layoutManager = QAndroidJniObject("android/support/v7/widget/LinearLayoutManager",
                                        "(Landroid/content/Context;)V",
                                        ctx().object());

    instance.callMethod<void>("setLayoutManager",
                              "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                              m_layoutManager.object());

    QtAndroidViewGroup::onInflate(instance);
}

void QtAndroidRecyclerView::updateAdapter()
{
    if (!isValid() || !m_adapter)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject adapter = m_adapter->instance();
    QtAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/support/v7/widget/RecyclerView$Adapter;)V", adapter.object());
    });
}
