#include "qtandroiddrawerlayoutparams_p.h"
#include "qtandroiddrawerlayout_p.h"
#include "qtandroidview_p.h"

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
        emit gravityChanged();
    }
}

QAndroidJniObject QtAndroidDrawerLayoutParams::onConstruct()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout$LayoutParams",
                             "(III)V",
                             MATCH_PARENT, MATCH_PARENT, m_gravity);
}

void QtAndroidDrawerLayoutParams::onInflate(QAndroidJniObject &params)
{
    QtAndroidMarginLayoutParams::onInflate(params);

    params.setField<int>("gravity", m_gravity);
}
