#ifndef QTANDROIDACTIONBARDRAWERTOGGLE_P_H
#define QTANDROIDACTIONBARDRAWERTOGGLE_P_H

#include "qtdroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidActionBarDrawerToggle : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidActionBarDrawerToggle(QObject *parent = 0);

    void construct(jobject activity, jobject drawer);
};

QT_END_NAMESPACE

#endif // QTANDROIDACTIONBARDRAWERTOGGLE_P_H
