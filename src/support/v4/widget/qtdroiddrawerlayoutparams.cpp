#include "qtdroiddrawerlayoutparams_p.h"
#include "qtdroiddrawerlayout_p.h"
#include "qtdroidview_p.h"

QtDroidDrawerLayoutParams::QtDroidDrawerLayoutParams(QtDroidView *view) :
    QtDroidMarginLayoutParams(view), m_gravity(0)
{
}

int QtDroidDrawerLayoutParams::gravity() const
{
    return m_gravity;
}

void QtDroidDrawerLayoutParams::setGravity(int value)
{
    if (m_gravity != value) {
        m_gravity = value;
        emit gravityChanged();
    }
}

QAndroidJniObject QtDroidDrawerLayoutParams::construct()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout$LayoutParams",
                             "(III)V",
                             MATCH_PARENT, MATCH_PARENT, m_gravity);
}

void QtDroidDrawerLayoutParams::inflate(QAndroidJniObject &params)
{
    QtDroidMarginLayoutParams::inflate(params);

    params.setField<int>("gravity", m_gravity);
}
