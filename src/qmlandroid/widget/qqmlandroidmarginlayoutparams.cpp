#include "qqmlandroidmarginlayoutparams_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidMarginLayoutParams::QQmlAndroidMarginLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidLayoutParams(view)
{
}

int QQmlAndroidMarginLayoutParams::margin() const
{
    if (m_margin.isNull())
        return 0;
    return m_margin.value();
}

void QQmlAndroidMarginLayoutParams::setMargin(int margin)
{
    if (m_margin.isNull() || m_margin.value() != margin) {
        m_margin = margin;
        invalidate();
        emit marginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return margin();
    return m_topMargin.value();
}

void QQmlAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (m_topMargin.isNull() || m_topMargin.value() != margin) {
        m_topMargin = margin;
        invalidate();
        emit topMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return margin();
    return m_leftMargin.value();
}

void QQmlAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (m_leftMargin.isNull() || m_leftMargin.value() != margin) {
        m_leftMargin = margin;
        invalidate();
        emit leftMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return margin();
    return m_rightMargin.value();
}

void QQmlAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (m_rightMargin.isNull() || m_rightMargin.value() != margin) {
        m_rightMargin = margin;
        invalidate();
        emit rightMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return margin();
    return m_bottomMargin.value();
}

void QQmlAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (m_bottomMargin.isNull() || m_bottomMargin.value() != margin) {
        m_bottomMargin = margin;
        invalidate();
        emit bottomMarginChanged();
    }
}

QAndroidJniObject QQmlAndroidMarginLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$MarginLayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QQmlAndroidMarginLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLayoutParams::onInflate(instance);

    instance.callMethod<void>("setMargins",
                              "(IIII)V",
                              leftMargin(),
                              topMargin(),
                              rightMargin(),
                              bottomMargin());
}

QT_END_NAMESPACE
