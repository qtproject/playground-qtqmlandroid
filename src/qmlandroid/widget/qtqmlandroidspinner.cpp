#include "qtqmlandroidspinner_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidSpinner::QQmlAndroidSpinner(QQmlAndroidView *parent) :
    QQmlAndroidAdapterView(parent)
{
}

QAndroidJniObject QQmlAndroidSpinner::onCreate()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidSpinner::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
