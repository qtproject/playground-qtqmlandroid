#include "qtandroidabsseekbar_p.h"

QtAndroidAbsSeekBar::QtAndroidAbsSeekBar(QtAndroidView *parent) : QtAndroidProgressBar(parent)
{
}

QAndroidJniObject QtAndroidAbsSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAbsSeekBar::onInflate()
{
    QtAndroidProgressBar::onInflate();
}
