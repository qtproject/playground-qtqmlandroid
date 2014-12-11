#include "qtandroidlinearlayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidLinearLayoutParams::QtAndroidLinearLayoutParams(QtAndroidView *view) : QtAndroidMarginLayoutParams(view)
{
}

int QtAndroidLinearLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtAndroidLinearLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

qreal QtAndroidLinearLayoutParams::weight() const
{
    if (m_weight.isNull())
        return 0.0; // TODO
    return m_weight.value();
}

void QtAndroidLinearLayoutParams::setWeight(qreal value)
{
    if (value != weight()) {
        m_weight = value;
        emit weightChanged();
    }
}

QAndroidJniObject QtAndroidLinearLayoutParams::construct()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidLinearLayoutParams::inflate(QAndroidJniObject &params)
{
    QtAndroidMarginLayoutParams::inflate(params);

    if (!m_gravity.isNull())
        params.setField<jint>("gravity", m_gravity.value());
    if (!m_weight.isNull())
        params.setField<jfloat>("weight", m_weight.value());
}
