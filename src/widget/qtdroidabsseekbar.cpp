#include "qtdroidabsseekbar_p.h"

QtDroidAbsSeekBar::QtDroidAbsSeekBar(QObject *parent) : QtDroidProgressBar(parent)
{
}

QAndroidJniObject QtDroidAbsSeekBar::construct(jobject context)
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             context);
}

void QtDroidAbsSeekBar::inflate(jobject context)
{
    QtDroidProgressBar::inflate(context);
}
