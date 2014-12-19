#include "qqmlandroidcardview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidCardView::QQmlAndroidCardView(QQmlAndroidView *parent) :
    QQmlAndroidFrameLayout(parent)
{
}

QAndroidJniObject QQmlAndroidCardView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/CardView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidCardView::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidFrameLayout::onInflate(instance);
}

QT_END_NAMESPACE
