#ifndef QTDROIDACTIONBARDRAWERTOGGLE_P_H
#define QTDROIDACTIONBARDRAWERTOGGLE_P_H

#include "qtdroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtDroidActionBarDrawerToggle : public QtDroidObject
{
    Q_OBJECT

public:
    explicit QtDroidActionBarDrawerToggle(QObject *parent = 0);

    void construct(jobject activity, jobject drawer);
};

QT_END_NAMESPACE

#endif // QTDROIDACTIONBARDRAWERTOGGLE_P_H
