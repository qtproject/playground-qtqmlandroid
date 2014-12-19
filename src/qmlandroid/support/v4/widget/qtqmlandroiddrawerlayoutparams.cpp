#include "qtqmlandroiddrawerlayoutparams_p.h"
#include "qtqmlandroiddrawerlayout_p.h"
#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidDrawerLayoutParams::QtQmlAndroidDrawerLayoutParams(QtQmlAndroidView *view) :
    QtQmlAndroidMarginLayoutParams(view), m_gravity(0)
{
}

int QtQmlAndroidDrawerLayoutParams::gravity() const
{
    return m_gravity;
}

void QtQmlAndroidDrawerLayoutParams::setGravity(int value)
{
    if (m_gravity != value) {
        m_gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

QAndroidJniObject QtQmlAndroidDrawerLayoutParams::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/DrawerLayout$LayoutParams",
                             "(III)V",
                             MATCH_PARENT, MATCH_PARENT, m_gravity);
}

void QtQmlAndroidDrawerLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QtQmlAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<int>("gravity", m_gravity);
}

QT_END_NAMESPACE
