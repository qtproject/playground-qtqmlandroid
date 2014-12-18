#include "qtandroidgraphicsmodule_p.h"

#include "qtandroidcolor_p.h"

#include "qtandroidcolordrawable_p.h"
#include "qtandroiddrawable_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerGraphicsModule(const char *uri)
{
    qmlRegisterSingletonType<QtAndroidColor>(uri, 0, 21, "Color", QtAndroidColor::provider);
}

void registerDrawableModule(const char *uri)
{
    qmlRegisterType<QtAndroidColorDrawable>(uri, 0, 21, "ColorDrawable");
    qmlRegisterType<QtAndroidDrawable>(uri, 0, 21, "Drawable");
}

}

QT_END_NAMESPACE
