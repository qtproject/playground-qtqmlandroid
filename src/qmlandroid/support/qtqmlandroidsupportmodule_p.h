#ifndef QTQMLANDROIDSUPPORTMODULE_P_H
#define QTQMLANDROIDSUPPORTMODULE_P_H

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
    Q_QMLANDROID_EXPORT void registerSupportV4WidgetModule(const char *uri);
    Q_QMLANDROID_EXPORT void registerSupportV7AppModule(const char *uri);
    Q_QMLANDROID_EXPORT void registerSupportV7WidgetModule(const char *uri);
}

QT_END_NAMESPACE

#endif // QTQMLANDROIDSUPPORTMODULE_P_H
