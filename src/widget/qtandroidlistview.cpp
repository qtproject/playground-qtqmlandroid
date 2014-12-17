#include "qtandroidlistview_p.h"

QT_BEGIN_NAMESPACE

QtAndroidListView::QtAndroidListView(QtAndroidView *parent) :
    QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidListView::onCreate()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidListView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
