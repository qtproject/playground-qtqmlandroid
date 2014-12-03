#include "qtdroidprogressbar_p.h"
#include "qtdroidfunctions_p.h"

QtDroidProgressBar::QtDroidProgressBar(QtDroidView *parent) :
    QtDroidView(parent), m_progress(0), m_indeterminate(false)
{
}

bool QtDroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

void QtDroidProgressBar::setIndeterminate(bool indeterminate)
{
    if (m_indeterminate != indeterminate) {
        m_indeterminate = indeterminate;
        QtDroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QtDroidProgressBar::progress() const
{
    return m_progress;
}

void QtDroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtDroid::callIntMethod(instance(), "setProgress", progress);
}

bool QtDroidProgressBar::updateProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QtDroidProgressBar::max() const
{
    if (m_max.isNull())
        return 100;
    return m_max.value();
}

void QtDroidProgressBar::setMax(int arg)
{
    if (arg != max()) {
        m_max = arg;
        QtDroid::callIntMethod(instance(), "setMax", arg);
        emit maxChanged();
    }
}

QtDroidProgressBar::Style QtDroidProgressBar::style() const
{
    if (m_style.isNull())
        return Medium;
    return m_style.value();
}

void QtDroidProgressBar::setStyle(Style style)
{
    m_style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QtDroidProgressBar::construct(jobject context)
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             context, 0, style());
}

void QtDroidProgressBar::inflate(jobject context)
{
    QtDroidView::inflate(context);

    QtDroid::callIntMethod(instance(), "setProgress", m_progress);
    QtDroid::callBoolMethod(instance(), "setIndeterminate", m_indeterminate);
    if (!m_max.isNull())
        QtDroid::callIntMethod(instance(), "setMax", m_max.value());
}
