#include "qtqmlandroidcardview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidCardView::QtQmlAndroidCardView(QtQmlAndroidView *parent) :
    QtQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtQmlAndroidCardView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/CardView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidCardView::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
