#include "qtqmlandroidappmodule_p.h"

#include "qqmlandroidactionbar_p.h"
#include "qqmlandroidactivity_p.h"
#include "qqmlandroidalertdialog_p.h"
#include "qqmlandroiddialog_p.h"
#include "qqmlandroidservice_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAppModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidActionBar>(uri, 0, 21, "ActionBar");
    qmlRegisterType<QQmlAndroidActivity>(uri, 0, 21, "Activity");
    qmlRegisterType<QQmlAndroidAlertDialog>(uri, 0, 21, "AlertDialog");
    qmlRegisterType<QQmlAndroidDialog>(uri, 0, 21, "Dialog");
    qmlRegisterType<QQmlAndroidService>(uri, 0, 21, "Service");
}

}

QT_END_NAMESPACE
