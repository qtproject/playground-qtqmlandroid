#include "qtandroidframelayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidFrameLayoutParams::QtAndroidFrameLayoutParams(QtAndroidView *view) : QtAndroidMarginLayoutParams(view)
{
}

int QtAndroidFrameLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtAndroidFrameLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

QAndroidJniObject QtAndroidFrameLayoutParams::onConstruct()
{
    return QAndroidJniObject("android/widget/FrameLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidFrameLayoutParams::onInflate(QAndroidJniObject &params)
{
    QtAndroidMarginLayoutParams::onInflate(params);

    if (!m_gravity.isNull())
        params.callMethod<void>("setGravity", "(I)V", m_gravity.value());
}
