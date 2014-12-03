#include "qtdroidlistview_p.h"

QtDroidListView::QtDroidListView(QtDroidView *parent) : QtDroidAdapterView(parent)
{
}

QAndroidJniObject QtDroidListView::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidListView::inflate(jobject context)
{
    QtDroidAdapterView::inflate(context);

    QAndroidJniObject view = instance();
    view.callMethod<void>("setBackgroundColor", "(I)V", -1); // TODO: Color.WHITE
}
