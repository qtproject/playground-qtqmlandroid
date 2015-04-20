#include "qqmlandroidlinearlayoutparams_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidLinearLayoutParams::QQmlAndroidLinearLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidMarginLayoutParams(view)
{
}

int QQmlAndroidLinearLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity;
}

void QQmlAndroidLinearLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

qreal QQmlAndroidLinearLayoutParams::weight() const
{
    if (m_weight.isNull())
        return 0.0; // TODO
    return m_weight;
}

void QQmlAndroidLinearLayoutParams::setWeight(qreal value)
{
    if (value != weight()) {
        m_weight = value;
        invalidate();
        emit weightChanged();
    }
}

QAndroidJniObject QQmlAndroidLinearLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QQmlAndroidLinearLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.setField<jint>("gravity", m_gravity);
    if (!m_weight.isNull())
        instance.setField<jfloat>("weight", m_weight);
}

QT_END_NAMESPACE
