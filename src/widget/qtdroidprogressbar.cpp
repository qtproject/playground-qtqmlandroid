#include "qtdroidprogressbar_p.h"
#include "qtdroidfunctions_p.h"

QtAndroidProgressBar::QtAndroidProgressBar(QtAndroidView *parent) :
    QtAndroidView(parent), m_progress(0), m_indeterminate(false)
{
}

bool QtAndroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

void QtAndroidProgressBar::setIndeterminate(bool indeterminate)
{
    if (m_indeterminate != indeterminate) {
        m_indeterminate = indeterminate;
        QtAndroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QtAndroidProgressBar::progress() const
{
    return m_progress;
}

void QtAndroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtAndroid::callIntMethod(instance(), "setProgress", progress);
}

bool QtAndroidProgressBar::updateProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QtAndroidProgressBar::max() const
{
    if (m_max.isNull())
        return 100;
    return m_max.value();
}

void QtAndroidProgressBar::setMax(int arg)
{
    if (arg != max()) {
        m_max = arg;
        QtAndroid::callIntMethod(instance(), "setMax", arg);
        emit maxChanged();
    }
}

QtAndroidProgressBar::Style QtAndroidProgressBar::style() const
{
    if (m_style.isNull())
        return Medium;
    return m_style.value();
}

void QtAndroidProgressBar::setStyle(Style style)
{
    m_style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QtAndroidProgressBar::construct()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QtAndroidProgressBar::inflate()
{
    QtAndroidView::inflate();

    QtAndroid::callIntMethod(instance(), "setProgress", m_progress);
    QtAndroid::callBoolMethod(instance(), "setIndeterminate", m_indeterminate);
    if (!m_max.isNull())
        QtAndroid::callIntMethod(instance(), "setMax", m_max.value());
}
