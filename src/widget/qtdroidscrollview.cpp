#include "qtdroidscrollview_p.h"

QtDroidScrollView::QtDroidScrollView(QtDroidView *parent) : QtDroidFrameLayout(parent)
{
}

QAndroidJniObject QtDroidScrollView::construct()
{
    return QAndroidJniObject("android/widget/ScrollView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidScrollView::inflate()
{
    QtDroidFrameLayout::inflate();
}
