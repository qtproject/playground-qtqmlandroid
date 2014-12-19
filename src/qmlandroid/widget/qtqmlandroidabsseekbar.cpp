#include "qtqmlandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAbsSeekBar::QQmlAndroidAbsSeekBar(QQmlAndroidView *parent) :
    QQmlAndroidProgressBar(parent)
{
}

QAndroidJniObject QQmlAndroidAbsSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/AbsSeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidAbsSeekBar::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidProgressBar::onInflate(instance);
}

QT_END_NAMESPACE
