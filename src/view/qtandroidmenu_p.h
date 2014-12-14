#ifndef QTANDROIDMENU_P_H
#define QTANDROIDMENU_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidMenuItem;

class QtAndroidMenu : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidMenu(QObject *parent = 0);

    QList<QtAndroidMenuItem *> items() const;

protected:
    QAndroidJniObject construct();
    void inflate();

private:
    friend class QtAndroidActivity;
};

QT_END_NAMESPACE

#endif // QTANDROIDMENU_P_H
