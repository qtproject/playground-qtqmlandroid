#include "qtdroidlistview_p.h"

QtAndroidListView::QtAndroidListView(QtAndroidView *parent) : QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidListView::construct()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidListView::inflate()
{
    QtAndroidAdapterView::inflate();

    QAndroidJniObject view = instance();
    view.callMethod<void>("setBackgroundColor", "(I)V", -1); // TODO: Color.WHITE
}
