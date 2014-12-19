#include "qtqmlandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAbsSeekBar::QtQmlAndroidAbsSeekBar(QtQmlAndroidView *parent) :
    QtQmlAndroidProgressBar(parent)
{
}

QAndroidJniObject QtQmlAndroidAbsSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtQmlAndroidAbsSeekBar::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidProgressBar::onInflate(instance);
}

QT_END_NAMESPACE
