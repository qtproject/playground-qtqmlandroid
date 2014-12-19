#ifndef QQMLANDROIDCONTEXT_P_H
#define QQMLANDROIDCONTEXT_P_H

#include "qqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidContext : public QQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QQmlAndroidContext(QObject *parent = 0);
    explicit QQmlAndroidContext(QQmlAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCONTEXT_P_H
