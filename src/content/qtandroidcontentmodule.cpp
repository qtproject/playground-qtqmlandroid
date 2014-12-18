#include "qtandroidwidgetmodule_p.h"

#include "qtandroidcontext_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerContentModule(const char *uri)
{
    qmlRegisterUncreatableType<QtAndroidContext>(uri, 0, 21, "Context", "Cannot create Context");
}

}

QT_END_NAMESPACE
