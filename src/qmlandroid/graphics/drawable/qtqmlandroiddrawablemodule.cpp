#include "qtqmlandroiddrawablemodule_p.h"

#include "qtqmlandroidcolordrawable_p.h"
#include "qtqmlandroiddrawable_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerDrawableModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidColorDrawable>(uri, 0, 21, "ColorDrawable");
    qmlRegisterType<QQmlAndroidDrawable>(uri, 0, 21, "Drawable");
}

}

QT_END_NAMESPACE
