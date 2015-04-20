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
    return m_margin;
}

void QQmlAndroidMarginLayoutParams::setMargin(int margin)
{
    if (m_margin.isNull() || m_margin != margin) {
        m_margin = margin;
        invalidate();
        emit marginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return margin();
    return m_topMargin;
}

void QQmlAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (m_topMargin.isNull() || m_topMargin != margin) {
        m_topMargin = margin;
        invalidate();
        emit topMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return margin();
    return m_leftMargin;
}

void QQmlAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (m_leftMargin.isNull() || m_leftMargin != margin) {
        m_leftMargin = margin;
        invalidate();
        emit leftMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return margin();
    return m_rightMargin;
}

void QQmlAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (m_rightMargin.isNull() || m_rightMargin != margin) {
        m_rightMargin = margin;
        invalidate();
        emit rightMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return margin();
    return m_bottomMargin;
}

void QQmlAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (m_bottomMargin.isNull() || m_bottomMargin != margin) {
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
