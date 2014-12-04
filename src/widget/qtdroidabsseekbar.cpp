#include "qtdroidabsseekbar_p.h"

QtDroidAbsSeekBar::QtDroidAbsSeekBar(QtDroidView *parent) : QtDroidProgressBar(parent)
{
}

QAndroidJniObject QtDroidAbsSeekBar::construct()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtDroidAbsSeekBar::inflate()
{
    QtDroidProgressBar::inflate();
}
