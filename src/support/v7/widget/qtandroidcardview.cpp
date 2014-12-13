#include "qtandroidcardview_p.h"

QtAndroidCardView::QtAndroidCardView(QtAndroidView *parent) : QtAndroidFrameLayout(parent)
{
}

QAndroidJniObject QtAndroidCardView::construct()
{
    return QAndroidJniObject("android/support/v7/widget/CardView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidCardView::inflate()
{
    QtAndroidFrameLayout::inflate();
}
