#include "qtdroidmarginlayoutparams_p.h"
#include "qtdroidview_p.h"

QtDroidMarginLayoutParams::QtDroidMarginLayoutParams(QtDroidView *view) : QtDroidLayoutParams(view)
{
}

int QtDroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return 0;
    return m_topMargin.value();
}

void QtDroidMarginLayoutParams::setTopMargin(int margin)
{
    if (margin != topMargin()) {
        m_topMargin = margin;
        emit topMarginChanged();
    }
}

int QtDroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return 0;
    return m_leftMargin.value();
}

void QtDroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (margin != leftMargin()) {
        m_leftMargin = margin;
        emit leftMarginChanged();
    }
}

int QtDroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return 0;
    return m_rightMargin.value();
}

void QtDroidMarginLayoutParams::setRightMargin(int margin)
{
    if (margin != rightMargin()) {
        m_rightMargin = margin;
        emit rightMarginChanged();
    }
}

int QtDroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return 0;
    return m_bottomMargin.value();
}

void QtDroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (margin != bottomMargin()) {
        m_bottomMargin = margin;
        emit bottomMarginChanged();
    }
}

QAndroidJniObject QtDroidMarginLayoutParams::construct()
{
    return QAndroidJniObject("android/view/ViewGroup$MarginLayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtDroidMarginLayoutParams::applyParams(QAndroidJniObject &params)
{
    QtDroidLayoutParams::applyParams(params);

    if (!m_topMargin.isNull() || !m_leftMargin.isNull() || !m_rightMargin.isNull() || !m_bottomMargin.isNull()) {
        params.callMethod<void>("setMargins",
                                "(IIII)V",
                                leftMargin(),
                                topMargin(),
                                rightMargin(),
                                bottomMargin());
    }
}
