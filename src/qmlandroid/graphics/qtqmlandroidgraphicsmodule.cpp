#include "qtqmlandroidgraphicsmodule_p.h"

#include "qtqmlandroidcolor_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerGraphicsModule(const char *uri)
{
    qmlRegisterSingletonType<QtQmlAndroidColor>(uri, 0, 21, "Color", QtQmlAndroidColor::provider);
}

}

QT_END_NAMESPACE
