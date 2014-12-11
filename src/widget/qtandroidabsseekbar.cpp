#include "qtandroidabsseekbar_p.h"

QtAndroidAbsSeekBar::QtAndroidAbsSeekBar(QtAndroidView *parent) : QtAndroidProgressBar(parent)
{
}

QAndroidJniObject QtAndroidAbsSeekBar::construct()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidAbsSeekBar::inflate()
{
    QtAndroidProgressBar::inflate();
}
