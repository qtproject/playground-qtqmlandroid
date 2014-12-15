#ifndef QTANDROIDCONTEXTWRAPPER_P_H
#define QTANDROIDCONTEXTWRAPPER_P_H

#include "qtandroidcontext_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidContextWrapper : public QtAndroidContext
{
    Q_OBJECT

public:
    explicit QtAndroidContextWrapper(QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTANDROIDCONTEXTWRAPPER_P_H
