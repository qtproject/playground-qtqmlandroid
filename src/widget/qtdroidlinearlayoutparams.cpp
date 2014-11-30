#include "qtdroidlinearlayoutparams_p.h"
#include "qtdroidview_p.h"

QtDroidLinearLayoutParams::QtDroidLinearLayoutParams(QtDroidView *view) : QtDroidLayoutParams(view)
{
}

QtDroidLinearLayoutParams *QtDroidLinearLayoutParams::qmlAttachedProperties(QObject *object)
{
    QtDroidView *view = qobject_cast<QtDroidView*>(object);
    if (view)
        return new QtDroidLinearLayoutParams(view);
    return 0;
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
        return 1.0; // TODO
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
    QtDroidLayoutParams::applyParams(params);

    if (!m_gravity.isNull())
        params.callMethod<void>("setGravity", "(I)V", m_gravity.value());
    if (!m_weight.isNull())
        params.callMethod<void>("setWeight", "(F)V", m_weight.value());
}
