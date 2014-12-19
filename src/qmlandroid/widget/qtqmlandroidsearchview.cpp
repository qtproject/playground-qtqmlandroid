#include "qtqmlandroidsearchview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSearchView::QtQmlAndroidSearchView(QtQmlAndroidView *parent) :
    QtQmlAndroidLinearLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidSearchView::onCreate()
{
    return QAndroidJniObject("android/widget/SearchView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSearchView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidLinearLayout::onInflate(instance);
}

QT_END_NAMESPACE
