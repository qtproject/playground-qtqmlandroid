#ifndef QTQMLANDROIDVIEWMODULE_P_H
#define QTQMLANDROIDVIEWMODULE_P_H

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

#include <QtQmlAndroid/private/qtqmlandroidglobal_p.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid
{
    Q_QMLANDROID_EXPORT void registerViewModule(const char *uri);
}

QT_END_NAMESPACE

#endif // QTQMLANDROIDVIEWMODULE_P_H
