#include "qtandroidrecyclerview_p.h"
#include "qtandroidbaseadapter_p.h"

QtAndroidRecyclerView::QtAndroidRecyclerView(QtAndroidView *parent) :
    QtAndroidViewGroup(parent), m_adapter(0)
{
}

QtAndroidBaseAdapter *QtAndroidRecyclerView::adapter() const
{
    return m_adapter;
}

void QtAndroidRecyclerView::setAdapter(QtAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        m_adapter = adapter;
        emit adapterChanged();
    }
}

QAndroidJniObject QtAndroidRecyclerView::construct()
{
    return QAndroidJniObject("android/support/v7/widget/RecyclerView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

#include <QtDebug>
void QtAndroidRecyclerView::inflate()
{
    QtAndroidViewGroup::inflate();

    QTANDROID_ASSERT_ANDROID_THREAD();
    qDebug() << "A" << ctx().isValid() << instance().isValid() << QAndroidJniObject::isClassAvailable("android/support/v7/widget/LinearLayoutManager");

    QAndroidJniObject lm("android/support/v7/widget/LinearLayoutManager",
                                            "(Landroid/content/Context;)V",
                                            ctx().object());

    qDebug("B");
    QAndroidJniObject view = instance();
    qDebug("C");
    view.callMethod<void>("setLayoutManager",
                          "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                          lm.object());
    qDebug("D");

    if (m_adapter)
        m_adapter->setup(this);
    qDebug("E");

    //m_layoutManager = lm;

    qDebug("F");
}
