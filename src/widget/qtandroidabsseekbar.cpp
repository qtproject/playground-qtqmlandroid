#include "qtandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAbsSeekBar::QtAndroidAbsSeekBar(QtAndroidView *parent) :
    QtAndroidProgressBar(parent)
{
}

QAndroidJniObject QtAndroidAbsSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAbsSeekBar::onInflate(QAndroidJniObject &instance)
{
    QtAndroidProgressBar::onInflate(instance);
}

QT_END_NAMESPACE
