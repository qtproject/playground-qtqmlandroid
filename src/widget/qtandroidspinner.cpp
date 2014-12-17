#include "qtandroidspinner_p.h"

QT_BEGIN_NAMESPACE

QtAndroidSpinner::QtAndroidSpinner(QtAndroidView *parent) :
    QtAndroidAdapterView(parent)
{
}

QAndroidJniObject QtAndroidSpinner::onCreate()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidSpinner::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
