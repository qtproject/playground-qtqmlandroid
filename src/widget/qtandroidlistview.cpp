#include "qtandroidlistview_p.h"

QtAndroidListView::QtAndroidListView(QtAndroidView *parent) : QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidListView::onCreate()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidListView::onInflate()
{
    QtAndroidAdapterView::onInflate();

    QAndroidJniObject view = instance();
    view.callMethod<void>("setBackgroundColor", "(I)V", -1); // TODO: Color.WHITE
}
