#ifndef QTANDROIDSERVICE_P_H
#define QTANDROIDSERVICE_P_H

#include "qtandroidcontextwrapper_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidService : public QtAndroidContextWrapper
{
    Q_OBJECT

public:
    explicit QtAndroidService(QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTANDROIDSERVICE_P_H
