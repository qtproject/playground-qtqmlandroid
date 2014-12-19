#include "qtqmlandroidcontentmodule_p.h"

#include "qqmlandroidcontext_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerContentModule(const char *uri)
{
    qmlRegisterUncreatableType<QQmlAndroidContext>(uri, 0, 21, "Context", "Cannot create Context");
}

}

QT_END_NAMESPACE
