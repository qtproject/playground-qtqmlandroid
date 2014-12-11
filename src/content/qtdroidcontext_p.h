#ifndef QTDROIDCONTEXT_P_H
#define QTDROIDCONTEXT_P_H

#include "qtdroidobject_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QtAndroidContext : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidContext(QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTDROIDCONTEXT_P_H
