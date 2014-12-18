#include "qtandroidsearchview_p.h"

QT_BEGIN_NAMESPACE

QtAndroidSearchView::QtAndroidSearchView(QtAndroidView *parent) :
    QtAndroidLinearLayout(parent)
{
}

QAndroidJniObject QtAndroidSearchView::onCreate()
{
    return QAndroidJniObject("android/widget/SearchView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSearchView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidLinearLayout::onInflate(instance);
}

QT_END_NAMESPACE
