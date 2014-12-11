#ifndef QTANDROIDDRAWERLAYOUT_P_H
#define QTANDROIDDRAWERLAYOUT_P_H

#include "qtdroidviewgroup_p.h"
#include "qtdroiddrawerlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidActionBarDrawerToggle;

class QtAndroidDrawerLayout : public QtAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QtAndroidDrawerLayout(QtAndroidView *parent = 0);

    static QtAndroidDrawerLayoutParams *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    void closeDrawers();
    void closeDrawer(int gravity);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;

    void childEvent(QChildEvent *event) Q_DECL_OVERRIDE;

private:
    QtAndroidActionBarDrawerToggle *m_toggle;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidDrawerLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDDRAWERLAYOUT_P_H
