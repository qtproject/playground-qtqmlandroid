#include "qtqmlandroidlinearlayoutparams_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidLinearLayoutParams::QtQmlAndroidLinearLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidMarginLayoutParams(view)
{
}

int QtQmlAndroidLinearLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtQmlAndroidLinearLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

qreal QtQmlAndroidLinearLayoutParams::weight() const
{
    if (m_weight.isNull())
        return 0.0; // TODO
    return m_weight.value();
}

void QtQmlAndroidLinearLayoutParams::setWeight(qreal value)
{
    if (value != weight()) {
        m_weight = value;
        invalidate();
        emit weightChanged();
    }
}

QAndroidJniObject QtQmlAndroidLinearLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtQmlAndroidLinearLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.setField<jint>("gravity", m_gravity.value());
    if (!m_weight.isNull())
        instance.setField<jfloat>("weight", m_weight.value());
}

QT_END_NAMESPACE
