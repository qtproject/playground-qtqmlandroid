#include "qtandroidmarginlayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidMarginLayoutParams::QtAndroidMarginLayoutParams(QtAndroidView *view) : QtAndroidLayoutParams(view)
{
}

int QtAndroidMarginLayoutParams::margin() const
{
    if (m_margin.isNull())
        return 0;
    return m_margin.value();
}

void QtAndroidMarginLayoutParams::setMargin(int margin)
{
    if (m_margin.isNull() || m_margin.value() != margin) {
        m_margin = margin;
        emit marginChanged();
    }
}

int QtAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return margin();
    return m_topMargin.value();
}

void QtAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (m_topMargin.isNull() || m_topMargin.value() != margin) {
        m_topMargin = margin;
        emit topMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return margin();
    return m_leftMargin.value();
}

void QtAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (m_leftMargin.isNull() || m_leftMargin.value() != margin) {
        m_leftMargin = margin;
        emit leftMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return margin();
    return m_rightMargin.value();
}

void QtAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (m_rightMargin.isNull() || m_rightMargin.value() != margin) {
        m_rightMargin = margin;
        emit rightMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return margin();
    return m_bottomMargin.value();
}

void QtAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (m_bottomMargin.isNull() || m_bottomMargin.value() != margin) {
        m_bottomMargin = margin;
        emit bottomMarginChanged();
    }
}

QAndroidJniObject QtAndroidMarginLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$MarginLayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidMarginLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtAndroidLayoutParams::onInflate(instance);

    instance.callMethod<void>("setMargins",
                              "(IIII)V",
                              leftMargin(),
                              topMargin(),
                              rightMargin(),
                              bottomMargin());
}
