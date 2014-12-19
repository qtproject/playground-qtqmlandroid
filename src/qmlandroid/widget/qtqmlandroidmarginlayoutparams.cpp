#include "qtqmlandroidmarginlayoutparams_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidMarginLayoutParams::QtQmlAndroidMarginLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidLayoutParams(view)
{
}

int QtQmlAndroidMarginLayoutParams::margin() const
{
    if (m_margin.isNull())
        return 0;
    return m_margin.value();
}

void QtQmlAndroidMarginLayoutParams::setMargin(int margin)
{
    if (m_margin.isNull() || m_margin.value() != margin) {
        m_margin = margin;
        invalidate();
        emit marginChanged();
    }
}

int QtQmlAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return margin();
    return m_topMargin.value();
}

void QtQmlAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (m_topMargin.isNull() || m_topMargin.value() != margin) {
        m_topMargin = margin;
        invalidate();
        emit topMarginChanged();
    }
}

int QtQmlAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return margin();
    return m_leftMargin.value();
}

void QtQmlAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (m_leftMargin.isNull() || m_leftMargin.value() != margin) {
        m_leftMargin = margin;
        invalidate();
        emit leftMarginChanged();
    }
}

int QtQmlAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return margin();
    return m_rightMargin.value();
}

void QtQmlAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (m_rightMargin.isNull() || m_rightMargin.value() != margin) {
        m_rightMargin = margin;
        invalidate();
        emit rightMarginChanged();
    }
}

int QtQmlAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return margin();
    return m_bottomMargin.value();
}

void QtQmlAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (m_bottomMargin.isNull() || m_bottomMargin.value() != margin) {
        m_bottomMargin = margin;
        invalidate();
        emit bottomMarginChanged();
    }
}

QAndroidJniObject QtQmlAndroidMarginLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$MarginLayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtQmlAndroidMarginLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidLayoutParams::onInflate(instance);

    instance.callMethod<void>("setMargins",
                              "(IIII)V",
                              leftMargin(),
                              topMargin(),
                              rightMargin(),
                              bottomMargin());
}

QT_END_NAMESPACE
