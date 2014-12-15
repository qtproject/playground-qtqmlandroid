#include "qtandroidcardview_p.h"

QtAndroidCardView::QtAndroidCardView(QtAndroidView *parent) :
    QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidCardView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/CardView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCardView::onInflate(QAndroidJniObject &instance)
{
    QtAndroidFrameLayout::onInflate(instance);
}
