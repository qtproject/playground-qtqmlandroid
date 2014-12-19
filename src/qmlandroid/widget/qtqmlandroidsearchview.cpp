#include "qtqmlandroidsearchview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSearchView::QQmlAndroidSearchView(QQmlAndroidView *parent) :
    QQmlAndroidLinearLayout(parent)
{
}

QAndroidJniObject QQmlAndroidSearchView::onCreate()
{
    return QAndroidJniObject("android/widget/SearchView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSearchView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLinearLayout::onInflate(instance);
}

QT_END_NAMESPACE
