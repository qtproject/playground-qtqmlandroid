#include "qtqmlandroidspinner_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidSpinner::QtQmlAndroidSpinner(QtQmlAndroidView *parent) :
    QtQmlAndroidAdapterView(parent)
{
}

QAndroidJniObject QtQmlAndroidSpinner::onCreate()
{
    return QAndroidJniObject("android/widget/Spinner",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidSpinner::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidAdapterView::onInflate(instance);
}

QT_END_NAMESPACE
