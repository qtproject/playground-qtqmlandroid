#include "qqmlandroiddrawerlayoutparams_p.h"
#include "qqmlandroiddrawerlayout_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidDrawerLayoutParams::QQmlAndroidDrawerLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidMarginLayoutParams(view), m_gravity(0)
{
}

int QQmlAndroidDrawerLayoutParams::gravity() const
{
    return m_gravity;
}

void QQmlAndroidDrawerLayoutParams::setGravity(int value)
{
    if (m_gravity != value) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QQmlAndroidDrawerLayoutParams::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout$LayoutParams",
                             "(III)V",
                             MATCH_PARENT, MATCH_PARENT, m_gravity);
}

void QQmlAndroidDrawerLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<int>("gravity", m_gravity);
}

QT_END_NAMESPACE
