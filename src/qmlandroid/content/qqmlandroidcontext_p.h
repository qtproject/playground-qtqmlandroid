#ifndef QQMLANDROIDCONTEXT_P_H
#define QQMLANDROIDCONTEXT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

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
