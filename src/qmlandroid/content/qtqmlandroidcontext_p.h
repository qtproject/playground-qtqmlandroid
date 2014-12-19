#ifndef QTQMLANDROIDCONTEXT_P_H
#define QTQMLANDROIDCONTEXT_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidContext : public QQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QQmlAndroidContext(QObject *parent = 0);
    explicit QQmlAndroidContext(QQmlAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCONTEXT_P_H
