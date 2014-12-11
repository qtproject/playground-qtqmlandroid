#ifndef QTDROIDACTIONBARDRAWERTOGGLE_P_H
#define QTDROIDACTIONBARDRAWERTOGGLE_P_H

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

#endif // QTDROIDACTIONBARDRAWERTOGGLE_P_H
