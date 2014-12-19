#include "qtqmlandroidmodule_p.h"

#include "qtqmlandroidr_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAndroidModule(const char *uri)
{
    qmlRegisterSingletonType<QQmlAndroidR>(uri, 0, 21, "R", QQmlAndroidR::provider);
}

}

QT_END_NAMESPACE
