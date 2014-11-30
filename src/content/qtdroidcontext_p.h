#ifndef QTDROIDCONTEXT_P_H
#define QTDROIDCONTEXT_P_H

#include "qtdroidobject_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QtDroidContext : public QtDroidObject
{
    Q_OBJECT

public:
    explicit QtDroidContext(QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTDROIDCONTEXT_P_H
