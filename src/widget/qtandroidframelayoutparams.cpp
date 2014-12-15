#include "qtandroidframelayoutparams_p.h"
#include "qtandroidview_p.h"

QtAndroidFrameLayoutParams::QtAndroidFrameLayoutParams(QtAndroidView *view) :
    QtAndroidMarginLayoutParams(view)
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
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QtAndroidFrameLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtAndroidFrameLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.callMethod<void>("setGravity", "(I)V", m_gravity.value());
}
