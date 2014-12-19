#include "qtqmlandroidprogressbar_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidProgressBar::QtQmlAndroidProgressBar(QtQmlAndroidView *parent) :
    QtQmlAndroidView(parent), m_max(100), m_progress(0), m_secondary(0), m_indeterminate(false)
{
}

bool QtQmlAndroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

void QtQmlAndroidProgressBar::setIndeterminate(bool indeterminate)
{
    if (m_indeterminate != indeterminate) {
        m_indeterminate = indeterminate;
        QtQmlAndroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QtQmlAndroidProgressBar::progress() const
{
    return m_progress;
}

void QtQmlAndroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtQmlAndroid::callIntMethod(instance(), "setProgress", progress);
}

bool QtQmlAndroidProgressBar::updateProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QtQmlAndroidProgressBar::secondaryProgress() const
{
    return m_secondary;
}

void QtQmlAndroidProgressBar::setSecondaryProgress(int progress)
{
    if (m_secondary != progress) {
        m_secondary = progress;
        QtQmlAndroid::callIntMethod(instance(), "setSecondaryProgress", progress);
        emit secondaryProgressChanged();
    }
}

int QtQmlAndroidProgressBar::max() const
{
    return m_max;
}

void QtQmlAndroidProgressBar::setMax(int max)
{
    if (m_max != max) {
        m_max = max;
        QtQmlAndroid::callIntMethod(instance(), "setMax", max);
        emit maxChanged();
    }
}

QtQmlAndroidProgressBar::Style QtQmlAndroidProgressBar::style() const
{
    if (m_style.isNull())
        return Medium;
    return m_style.value();
}

void QtQmlAndroidProgressBar::setStyle(Style style)
{
    m_style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QtQmlAndroidProgressBar::onCreate()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QtQmlAndroidProgressBar::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidView::onInflate(instance);

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
