#include <QtQml>

#include "qtdroidactionbar_p.h"
#include "qtdroidactivity_p.h"

#include "qtdroidcontext_p.h"

#include "qtdroidcolor_p.h"

#include "qtdroidr_p.h"

#include "qtdroidgravity_p.h"
#include "qtdroidlayoutparams_p.h"
#include "qtdroidmenu_p.h"
#include "qtdroidmenuitem_p.h"
#include "qtdroidview_p.h"
#include "qtdroidviewgroup_p.h"

#include "qtdroidarrayadapter_p.h"
#include "qtdroidbutton_p.h"
#include "qtdroidcalendarview_p.h"
#include "qtdroidcheckbox_p.h"
#include "qtdroidedittext_p.h"
#include "qtdroidframelayout_p.h"
#include "qtdroidframelayoutparams_p.h"
#include "qtdroidlinearlayout_p.h"
#include "qtdroidlinearlayoutparams_p.h"
#include "qtdroidlistview_p.h"
#include "qtdroidpopupmenu_p.h"
#include "qtdroidprogressbar_p.h"
#include "qtdroidradiobutton_p.h"
#include "qtdroidradiogroup_p.h"
#include "qtdroidrelativelayout_p.h"
#include "qtdroidrelativelayoutparams_p.h"
#include "qtdroidscrollview_p.h"
#include "qtdroidseekbar_p.h"
#include "qtdroidspace_p.h"
#include "qtdroidspinner_p.h"
#include "qtdroidswitch_p.h"
#include "qtdroidtabhost_p.h"
#include "qtdroidtabspec_p.h"
#include "qtdroidtabwidget_p.h"
#include "qtdroidtextview_p.h"
#include "qtdroidtogglebutton_p.h"
#include "qtdroidviewanimator_p.h"
#include "qtdroidviewflipper_p.h"
#include "qtdroidviewswitcher_p.h"

#include "qtdroiddrawerlayout_p.h"

#include "qtdroidactionbardrawertoggle_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qRegisterMetaType<QQmlPropertyMap *>();

    qmlRegisterType<QtAndroidActionBar>("qtdroid.app", 0, 1, "ActionBar");
    qmlRegisterType<QtAndroidActivity>("qtdroid.app", 0, 1, "Activity");

    qmlRegisterType<QtAndroidContext>();

    qmlRegisterSingletonType<QtAndroidColor>("qtdroid.graphics", 0, 1, "Color", QtAndroidColor::provider);

    qmlRegisterSingletonType<QtAndroidR>("qtdroid.R", 0, 1, "R", QtAndroidR::provider);

    qmlRegisterUncreatableType<QtAndroidGravity>("qtdroid.view", 0, 1, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>("qtdroid.view", 0, 1, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>("qtdroid.view", 0, 1, "Menu");
    qmlRegisterType<QtAndroidMenuItem>("qtdroid.view", 0, 1, "MenuItem");
    qmlRegisterType<QtAndroidView>("qtdroid.view", 0, 1, "View");
    qmlRegisterType<QtAndroidViewGroup>();

    qmlRegisterType<QtAndroidArrayAdapter>("qtdroid.widget", 0, 1, "ArrayAdapter");
    qmlRegisterType<QtAndroidBaseAdapter>();
    qmlRegisterType<QtAndroidButton>("qtdroid.widget", 0, 1, "Button");
    qmlRegisterType<QtAndroidCalendarView>("qtdroid.widget", 0, 1, "CalendarView");
    qmlRegisterType<QtAndroidCheckBox>("qtdroid.widget", 0, 1, "CheckBox");
    qmlRegisterType<QtAndroidEditText>("qtdroid.widget", 0, 1, "EditText");
    qmlRegisterType<QtAndroidFrameLayout>("qtdroid.widget", 0, 1, "FrameLayout");
    qmlRegisterType<QtAndroidFrameLayoutParams>();
    qmlRegisterType<QtAndroidLinearLayout>("qtdroid.widget", 0, 1, "LinearLayout");
    qmlRegisterType<QtAndroidLinearLayoutParams>();
    qmlRegisterType<QtAndroidListView>("qtdroid.widget", 0, 1, "ListView");
    qmlRegisterType<QtAndroidPopupMenu>("qtdroid.widget", 0, 1, "PopupMenu");
    qmlRegisterType<QtAndroidProgressBar>("qtdroid.widget", 0, 1, "ProgressBar");
    qmlRegisterType<QtAndroidRadioButton>("qtdroid.widget", 0, 1, "RadioButton");
    qmlRegisterType<QtAndroidRadioGroup>("qtdroid.widget", 0, 1, "RadioGroup");
    qmlRegisterType<QtAndroidRelativeLayout>("qtdroid.widget", 0, 1, "RelativeLayout");
    qmlRegisterType<QtAndroidRelativeLayoutParams>();
    qmlRegisterType<QtAndroidScrollView>("qtdroid.widget", 0, 1, "ScrollView");
    qmlRegisterType<QtAndroidSeekBar>("qtdroid.widget", 0, 1, "SeekBar");
    qmlRegisterType<QtAndroidSpace>("qtdroid.widget", 0, 1, "Space");
    qmlRegisterType<QtAndroidSpinner>("qtdroid.widget", 0, 1, "Spinner");
    qmlRegisterType<QtAndroidSwitch>("qtdroid.widget", 0, 1, "Switch");
    qmlRegisterType<QtAndroidTabHost>("qtdroid.widget", 0, 1, "TabHost");
    qmlRegisterUncreatableType<QtAndroidTabSpec>("qtdroid.widget", 0, 1, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtAndroidTabWidget>("qtdroid.widget", 0, 1, "TabWidget");
    qmlRegisterType<QtAndroidTextView>("qtdroid.widget", 0, 1, "TextView");
    qmlRegisterType<QtAndroidToggleButton>("qtdroid.widget", 0, 1, "ToggleButton");
    qmlRegisterType<QtAndroidViewAnimator>("qtdroid.widget", 0, 1, "ViewAnimator");
    qmlRegisterType<QtAndroidViewFlipper>("qtdroid.widget", 0, 1, "ViewFlipper");
    qmlRegisterType<QtAndroidViewSwitcher>("qtdroid.widget", 0, 1, "ViewSwitcher");

    qmlRegisterType<QtAndroidDrawerLayout>("qtdroid.support.v4.widget", 0, 1, "DrawerLayout");

    qmlRegisterType<QtAndroidActionBarDrawerToggle>("qtdroid.support.v7.app", 0, 1, "ActionBarDrawerToggle");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
