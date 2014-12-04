#include "qtdroidlistview_p.h"

QtDroidListView::QtDroidListView(QtDroidView *parent) : QtDroidAdapterView(parent)
{
}

QAndroidJniObject QtDroidListView::construct()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidListView::inflate()
{
    QtDroidAdapterView::inflate();

    QAndroidJniObject view = instance();
    view.callMethod<void>("setBackgroundColor", "(I)V", -1); // TODO: Color.WHITE
}
