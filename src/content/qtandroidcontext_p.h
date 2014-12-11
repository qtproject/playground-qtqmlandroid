#ifndef QTANDROIDCONTEXT_P_H
#define QTANDROIDCONTEXT_P_H

#include "qtandroidobject_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QtAndroidContext : public QtAndroidObject
{
    Q_OBJECT

public:
    explicit QtAndroidContext(QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTANDROIDCONTEXT_P_H
