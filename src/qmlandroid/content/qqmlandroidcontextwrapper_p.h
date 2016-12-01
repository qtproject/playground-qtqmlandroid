#ifndef QQMLANDROIDCONTEXTWRAPPER_P_H
#define QQMLANDROIDCONTEXTWRAPPER_P_H

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

#include "qqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidContextWrapper : public QQmlAndroidContext
{
    Q_OBJECT

public:
    explicit QQmlAndroidContextWrapper(QObject *parent = 0);
    explicit QQmlAndroidContextWrapper(QQmlAndroidContext *context, QObject *parent = 0);
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCONTEXTWRAPPER_P_H
