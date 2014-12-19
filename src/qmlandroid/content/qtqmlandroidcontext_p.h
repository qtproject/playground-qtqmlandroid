#ifndef QTQMLANDROIDCONTEXT_P_H
#define QTQMLANDROIDCONTEXT_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidContext : public QtQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QtQmlAndroidContext(QObject *parent = 0);
    explicit QtQmlAndroidContext(QtQmlAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCONTEXT_P_H
