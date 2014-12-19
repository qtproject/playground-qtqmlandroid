#include "qqmlandroidframelayoutparams_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidFrameLayoutParams::QQmlAndroidFrameLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidMarginLayoutParams(view)
{
}

int QQmlAndroidFrameLayoutParams::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity.value();
}

void QQmlAndroidFrameLayoutParams::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QQmlAndroidFrameLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/FrameLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QQmlAndroidFrameLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidMarginLayoutParams::onInflate(instance);

    if (!m_gravity.isNull())
        instance.callMethod<void>("setGravity", "(I)V", m_gravity.value());
}

QT_END_NAMESPACE
