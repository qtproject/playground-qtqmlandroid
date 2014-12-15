#include "qtandroidlinearlayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidLinearLayoutParams::QtAndroidLinearLayoutParams(QtAndroidView *view) :
    QtAndroidMarginLayoutParams(view)
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
        invalidate();
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
        invalidate();
        emit weightChanged();
    }
}

QAndroidJniObject QtAndroidLinearLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidLinearLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.setField<jint>("gravity", m_gravity.value());
    if (!m_weight.isNull())
        instance.setField<jfloat>("weight", m_weight.value());
}
