#include "qtandroidprogressbar_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidProgressBar::QtAndroidProgressBar(QtAndroidView *parent) :
    QtAndroidView(parent), m_max(100), m_progress(0), m_secondary(0), m_indeterminate(false)
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

int QtAndroidProgressBar::secondaryProgress() const
{
    return m_secondary;
}

void QtAndroidProgressBar::setSecondaryProgress(int progress)
{
    if (m_secondary != progress) {
        m_secondary = progress;
        QtAndroid::callIntMethod(instance(), "setSecondaryProgress", progress);
        emit secondaryProgressChanged();
    }
}

int QtAndroidProgressBar::max() const
{
    return m_max;
}

void QtAndroidProgressBar::setMax(int max)
{
    if (m_max != max) {
        m_max = max;
        QtAndroid::callIntMethod(instance(), "setMax", max);
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

QAndroidJniObject QtAndroidProgressBar::onCreate()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QtAndroidProgressBar::onInflate(QAndroidJniObject &instance)
{
    QtAndroidView::onInflate(instance);

    if (m_progress > 0)
        instance.callMethod<void>("setProgress", "(I)V", m_progress);
    if (m_secondary > 0)
        instance.callMethod<void>("setSecondaryProgress", "(I)V", m_secondary);
    if (m_indeterminate)
        instance.callMethod<void>("setIndeterminate", "(Z)V", m_indeterminate);
    if (m_max != 100)
        instance.callMethod<void>("setMax", "(I)V", m_max);
}

QT_END_NAMESPACE
