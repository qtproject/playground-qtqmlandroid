#ifndef QTANDROIDDRAWERLAYOUT_P_H
#define QTANDROIDDRAWERLAYOUT_P_H

#include "qtandroidviewgroup_p.h"
#include "qtandroiddrawerlayoutparams_p.h"

QT_BEGIN_NAMESPACE

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
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidDrawerLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDDRAWERLAYOUT_P_H
