#include "qtandroiddrawerlayoutparams_p.h"
#include "qtandroiddrawerlayout_p.h"
#include "qtandroidview_p.h"

QT_BEGIN_NAMESPACE

QtAndroidDrawerLayoutParams::QtAndroidDrawerLayoutParams(QtAndroidView *view) :
    QtAndroidMarginLayoutParams(view), m_gravity(0)
{
}

int QtAndroidDrawerLayoutParams::gravity() const
{
    return m_gravity;
}

void QtAndroidDrawerLayoutParams::setGravity(int value)
{
    if (m_gravity != value) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QtAndroidDrawerLayoutParams::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout$LayoutParams",
                             "(III)V",
                             MATCH_PARENT, MATCH_PARENT, m_gravity);
}

void QtAndroidDrawerLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<int>("gravity", m_gravity);
}

QT_END_NAMESPACE
