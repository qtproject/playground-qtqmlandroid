#ifndef QTANDROIDACTIONBARDRAWERTOGGLE_P_H
#define QTANDROIDACTIONBARDRAWERTOGGLE_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidActionBarDrawerToggle : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidActionBarDrawerToggle(QObject *parent = 0);

    void construct(const QAndroidJniObject &activity, const QAndroidJniObject &drawer);
};

QT_END_NAMESPACE

#endif // QTANDROIDACTIONBARDRAWERTOGGLE_P_H