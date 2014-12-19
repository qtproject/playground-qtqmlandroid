#include "qtqmlandroidlistview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidListView::QtQmlAndroidListView(QtQmlAndroidView *parent) :
    QtQmlAndroidAdapterView(parent)
{
}

QAndroidJniObject QtQmlAndroidListView::onCreate()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidListView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
