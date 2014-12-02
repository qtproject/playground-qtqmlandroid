#include "qtdroidframelayoutparams_p.h"
#include "qtdroidview_p.h"

QtDroidFrameLayoutParams::QtDroidFrameLayoutParams(QtDroidView *view) : QtDroidMarginLayoutParams(view)
{
}

int QtDroidFrameLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtDroidFrameLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

QAndroidJniObject QtDroidFrameLayoutParams::construct()
{
    return QAndroidJniObject("android/widget/FrameLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtDroidFrameLayoutParams::applyParams(QAndroidJniObject &params)
{
    QtDroidMarginLayoutParams::applyParams(params);

    if (!m_gravity.isNull())
        params.callMethod<void>("setGravity", "(I)V", m_gravity.value());
}
