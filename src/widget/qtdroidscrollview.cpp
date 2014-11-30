#include "qtdroidscrollview_p.h"

QtDroidScrollView::QtDroidScrollView(QObject *parent) : QtDroidFrameLayout(parent)
{
}

QAndroidJniObject QtDroidScrollView::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ScrollView",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidScrollView::inflate(jobject context)
{
    QtDroidFrameLayout::inflate(context);
}
