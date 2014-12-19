#include "qqmlandroidlistview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidListView::QQmlAndroidListView(QQmlAndroidView *parent) :
    QQmlAndroidAdapterView(parent)
{
}

QAndroidJniObject QQmlAndroidListView::onCreate()
{
    return QAndroidJniObject("android/widget/ListView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidListView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
