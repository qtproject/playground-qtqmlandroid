#include "qtdroidprogressbar_p.h"

QtDroidProgressBar::QtDroidProgressBar(QObject *parent) : QtDroidView(parent), m_indeterminate(false)
{
}

bool QtDroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

static void callSetIndeterminate(const QAndroidJniObject& bar, bool indeterminate)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            bar.callMethod<void>("setIndeterminate", "(Z)V", indeterminate);
        });
    }
}

void QtDroidProgressBar::setIndeterminate(bool arg)
{
    if (arg != isIndeterminate()) {
        m_indeterminate = arg;
        callSetIndeterminate(instance(), arg);
        emit indeterminateChanged();
    }
}

int QtDroidProgressBar::progress() const
{
    if (m_progress.isNull())
        return 0;
    return m_progress.value();
}

static void callSetProgress(const QAndroidJniObject& bar, int progress)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            bar.callMethod<void>("setProgress", "(I)V", progress);
        });
    }
}

void QtDroidProgressBar::setProgress(int arg)
{
    if (updateProgress(arg))
        callSetProgress(instance(), arg);
}

bool QtDroidProgressBar::updateProgress(int arg)
{
    if (arg != progress()) {
        m_progress = arg;
        callSetProgress(instance(), arg);
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

static void callSetMax(const QAndroidJniObject& bar, int max)
{
    if (bar.isValid()) {
        QtDroidObject::callUiMethod([=]() {
            bar.callMethod<void>("setMax", "(I)V", max);
        });
    }
}

void QtDroidProgressBar::setMax(int arg)
{
    if (arg != max()) {
        m_max = arg;
        callSetMax(instance(), arg);
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

    callSetIndeterminate(instance(), m_indeterminate);
    if (!m_max.isNull())
        callSetMax(instance(), m_max.value());
    if (!m_progress.isNull())
        callSetProgress(instance(), m_progress.value());
}
