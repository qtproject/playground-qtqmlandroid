#ifndef QTQMLANDROIDACTIONBARDRAWERTOGGLE_P_H
#define QTQMLANDROIDACTIONBARDRAWERTOGGLE_P_H

#include "qtqmlandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidActionBarDrawerToggle : public QQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QQmlAndroidActionBarDrawerToggle(QObject *parent = 0);

    void onCreate(const QAndroidJniObject &activity, const QAndroidJniObject &drawer);
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDACTIONBARDRAWERTOGGLE_P_H
