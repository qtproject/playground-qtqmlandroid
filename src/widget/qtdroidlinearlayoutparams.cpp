#include "qtdroidlinearlayoutparams_p.h"
#include "qtdroidlinearlayout_p.h"

QtDroidLinearLayoutParams::QtDroidLinearLayoutParams(QtDroidLinearLayout *layout) : QtDroidLayoutParams(layout)
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
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
        emit gravityChanged();
    }
}

qreal QtDroidLinearLayoutParams::weight() const
{
    if (m_weight.isNull())
        return 1.0; // TODO
    return m_weight.value();
}

void QtDroidLinearLayoutParams::setWeight(qreal value)
{
    if (value != weight()) {
        m_weight = value;
//        if (isValid())
//            jniObject().callMethod<void>("applyText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(txt).object());
        emit weightChanged();
    }
}

void QtDroidLinearLayoutParams::applyParams(QtDroidView *view)
{
    if (!m_gravity.isNull())
        ;
    if (!m_weight.isNull())
        ;
}
