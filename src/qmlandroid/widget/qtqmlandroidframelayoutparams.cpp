#include "qtqmlandroidframelayoutparams_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidFrameLayoutParams::QtQmlAndroidFrameLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidMarginLayoutParams(view)
{
}

int QtQmlAndroidFrameLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QtQmlAndroidFrameLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QtQmlAndroidFrameLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QtQmlAndroidFrameLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.callMethod<void>("setGravity", "(I)V", m_gravity.value());
}

QT_END_NAMESPACE
