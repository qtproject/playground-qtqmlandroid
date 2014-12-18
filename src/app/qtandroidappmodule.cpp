#include "qtandroidappmodule_p.h"

#include "qtandroidactionbar_p.h"
#include "qtandroidactivity_p.h"
#include "qtandroidalertdialog_p.h"
#include "qtandroiddialog_p.h"
#include "qtandroidservice_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerAppModule(const char *uri)
{
    qmlRegisterType<QtAndroidActionBar>(uri, 0, 21, "ActionBar");
    qmlRegisterType<QtAndroidActivity>(uri, 0, 21, "Activity");
    qmlRegisterType<QtAndroidAlertDialog>(uri, 0, 21, "AlertDialog");
    qmlRegisterType<QtAndroidDialog>(uri, 0, 21, "Dialog");
    qmlRegisterType<QtAndroidService>(uri, 0, 21, "Service");
}

}

QT_END_NAMESPACE
