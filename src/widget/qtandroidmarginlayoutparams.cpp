#include "qtandroidmarginlayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidMarginLayoutParams::QtAndroidMarginLayoutParams(QtAndroidView *view) : QtAndroidLayoutParams(view)
{
}

int QtAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return 0;
    return m_topMargin.value();
}

void QtAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (margin != topMargin()) {
        m_topMargin = margin;
        emit topMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return 0;
    return m_leftMargin.value();
}

void QtAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (margin != leftMargin()) {
        m_leftMargin = margin;
        emit leftMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return 0;
    return m_rightMargin.value();
}

void QtAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (margin != rightMargin()) {
        m_rightMargin = margin;
        emit rightMarginChanged();
    }
}

int QtAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return 0;
    return m_bottomMargin.value();
}

void QtAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (margin != bottomMargin()) {
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

    if (!m_topMargin.isNull() || !m_leftMargin.isNull() || !m_rightMargin.isNull() || !m_bottomMargin.isNull()) {
        instance.callMethod<void>("setMargins",
                                  "(IIII)V",
                                  leftMargin(),
                                  topMargin(),
                                  rightMargin(),
                                  bottomMargin());
    }
}
