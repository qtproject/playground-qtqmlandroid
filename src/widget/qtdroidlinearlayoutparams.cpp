#include "qtdroidlinearlayoutparams_p.h"
#include "qtdroidview_p.h"

QtDroidLinearLayoutParams::QtDroidLinearLayoutParams(QtDroidView *view) : QtDroidMarginLayoutParams(view)
{
}

int QtDroidLinearLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtDroidLinearLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

qreal QtDroidLinearLayoutParams::weight() const
{
    if (m_weight.isNull())
        return 0.0; // TODO
    return m_weight.value();
}

void QtDroidLinearLayoutParams::setWeight(qreal value)
{
    if (value != weight()) {
        m_weight = value;
        emit weightChanged();
    }
}

QAndroidJniObject QtDroidLinearLayoutParams::construct()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtDroidLinearLayoutParams::applyParams(QAndroidJniObject &params)
{
    QtDroidMarginLayoutParams::applyParams(params);

    if (!m_gravity.isNull())
        params.setField<jint>("gravity", m_gravity.value());
    if (!m_weight.isNull())
        params.setField<jfloat>("weight", m_weight.value());
}
