#include "qtqmlandroidgraphicsmodule_p.h"

#include "qtqmlandroidcolor_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerGraphicsModule(const char *uri)
{
    qmlRegisterSingletonType<QQmlAndroidColor>(uri, 0, 21, "Color", QQmlAndroidColor::provider);
}

}

QT_END_NAMESPACE
