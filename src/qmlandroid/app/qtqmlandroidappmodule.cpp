#include "qtqmlandroidappmodule_p.h"

#include "qtqmlandroidactionbar_p.h"
#include "qtqmlandroidactivity_p.h"
#include "qtqmlandroidalertdialog_p.h"
#include "qtqmlandroiddialog_p.h"
#include "qtqmlandroidservice_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAppModule(const char *uri)
{
    qmlRegisterType<QtQmlAndroidActionBar>(uri, 0, 21, "ActionBar");
    qmlRegisterType<QtQmlAndroidActivity>(uri, 0, 21, "Activity");
    qmlRegisterType<QtQmlAndroidAlertDialog>(uri, 0, 21, "AlertDialog");
    qmlRegisterType<QtQmlAndroidDialog>(uri, 0, 21, "Dialog");
    qmlRegisterType<QtQmlAndroidService>(uri, 0, 21, "Service");
}

}

QT_END_NAMESPACE
