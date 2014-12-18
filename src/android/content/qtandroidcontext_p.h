#ifndef QTANDROIDCONTEXT_P_H
#define QTANDROIDCONTEXT_P_H

#include "qtandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidContext : public QtAndroidContextual
{
    Q_OBJECT

public:
    explicit QtAndroidContext(QObject *parent = 0);
    explicit QtAndroidContext(QtAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTANDROIDCONTEXT_P_H
