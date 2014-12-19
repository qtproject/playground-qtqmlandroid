#include "qtqmlandroidprogressbar_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidProgressBar::QQmlAndroidProgressBar(QQmlAndroidView *parent) :
    QQmlAndroidView(parent), m_max(100), m_progress(0), m_secondary(0), m_indeterminate(false)
{
}

bool QQmlAndroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

void QQmlAndroidProgressBar::setIndeterminate(bool indeterminate)
{
    if (m_indeterminate != indeterminate) {
        m_indeterminate = indeterminate;
        QtQmlAndroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QQmlAndroidProgressBar::progress() const
{
    return m_progress;
}

void QQmlAndroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtQmlAndroid::callIntMethod(instance(), "setProgress", progress);
}

bool QQmlAndroidProgressBar::updateProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QQmlAndroidProgressBar::secondaryProgress() const
{
    return m_secondary;
}

void QQmlAndroidProgressBar::setSecondaryProgress(int progress)
{
    if (m_secondary != progress) {
        m_secondary = progress;
        QtQmlAndroid::callIntMethod(instance(), "setSecondaryProgress", progress);
        emit secondaryProgressChanged();
    }
}

int QQmlAndroidProgressBar::max() const
{
    return m_max;
}

void QQmlAndroidProgressBar::setMax(int max)
{
    if (m_max != max) {
        m_max = max;
        QtQmlAndroid::callIntMethod(instance(), "setMax", max);
        emit maxChanged();
    }
}

QQmlAndroidProgressBar::Style QQmlAndroidProgressBar::style() const
{
    if (m_style.isNull())
        return Medium;
    return m_style.value();
}

void QQmlAndroidProgressBar::setStyle(Style style)
{
    m_style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QQmlAndroidProgressBar::onCreate()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QQmlAndroidProgressBar::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);

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
