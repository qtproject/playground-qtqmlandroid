#include <QtQml>

#include "qtandroidactionbar_p.h"
#include "qtandroidactivity_p.h"

#include "qtandroidcontext_p.h"

#include "qtandroidcolor_p.h"

#include "qtandroidr_p.h"

#include "qtandroidgravity_p.h"
#include "qtandroidlayoutparams_p.h"
#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"
#include "qtandroidview_p.h"
#include "qtandroidviewgroup_p.h"

#include "qtandroidarrayadapter_p.h"
#include "qtandroidbutton_p.h"
#include "qtandroidcalendarview_p.h"
#include "qtandroidcheckbox_p.h"
#include "qtandroidedittext_p.h"
#include "qtandroidframelayout_p.h"
#include "qtandroidframelayoutparams_p.h"
#include "qtandroidlinearlayout_p.h"
#include "qtandroidlinearlayoutparams_p.h"
#include "qtandroidlistview_p.h"
#include "qtandroidpopupmenu_p.h"
#include "qtandroidprogressbar_p.h"
#include "qtandroidradiobutton_p.h"
#include "qtandroidradiogroup_p.h"
#include "qtandroidrelativelayout_p.h"
#include "qtandroidrelativelayoutparams_p.h"
#include "qtandroidscrollview_p.h"
#include "qtandroidseekbar_p.h"
#include "qtandroidspace_p.h"
#include "qtandroidspinner_p.h"
#include "qtandroidswitch_p.h"
#include "qtandroidtabhost_p.h"
#include "qtandroidtabspec_p.h"
#include "qtandroidtabwidget_p.h"
#include "qtandroidtextview_p.h"
#include "qtandroidtogglebutton_p.h"
#include "qtandroidviewanimator_p.h"
#include "qtandroidviewflipper_p.h"
#include "qtandroidviewswitcher_p.h"

#include "qtandroiddrawerlayout_p.h"

#include "qtandroidactionbardrawertoggle_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qRegisterMetaType<QQmlPropertyMap *>();

    qmlRegisterType<QtAndroidActionBar>("android.app", 0, 1, "ActionBar");
    qmlRegisterType<QtAndroidActivity>("android.app", 0, 1, "Activity");

    qmlRegisterType<QtAndroidContext>();

    qmlRegisterSingletonType<QtAndroidColor>("android.graphics", 0, 1, "Color", QtAndroidColor::provider);

    qmlRegisterSingletonType<QtAndroidR>("android.R", 0, 1, "R", QtAndroidR::provider);

    qmlRegisterUncreatableType<QtAndroidGravity>("android.view", 0, 1, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>("android.view", 0, 1, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>("android.view", 0, 1, "Menu");
    qmlRegisterType<QtAndroidMenuItem>("android.view", 0, 1, "MenuItem");
    qmlRegisterType<QtAndroidView>("android.view", 0, 1, "View");
    qmlRegisterType<QtAndroidViewGroup>();

    qmlRegisterType<QtAndroidArrayAdapter>("android.widget", 0, 1, "ArrayAdapter");
    qmlRegisterType<QtAndroidBaseAdapter>();
    qmlRegisterType<QtAndroidButton>("android.widget", 0, 1, "Button");
    qmlRegisterType<QtAndroidCalendarView>("android.widget", 0, 1, "CalendarView");
    qmlRegisterType<QtAndroidCheckBox>("android.widget", 0, 1, "CheckBox");
    qmlRegisterType<QtAndroidEditText>("android.widget", 0, 1, "EditText");
    qmlRegisterType<QtAndroidFrameLayout>("android.widget", 0, 1, "FrameLayout");
    qmlRegisterType<QtAndroidFrameLayoutParams>();
    qmlRegisterType<QtAndroidLinearLayout>("android.widget", 0, 1, "LinearLayout");
    qmlRegisterType<QtAndroidLinearLayoutParams>();
    qmlRegisterType<QtAndroidListView>("android.widget", 0, 1, "ListView");
    qmlRegisterType<QtAndroidPopupMenu>("android.widget", 0, 1, "PopupMenu");
    qmlRegisterType<QtAndroidProgressBar>("android.widget", 0, 1, "ProgressBar");
    qmlRegisterType<QtAndroidRadioButton>("android.widget", 0, 1, "RadioButton");
    qmlRegisterType<QtAndroidRadioGroup>("android.widget", 0, 1, "RadioGroup");
    qmlRegisterType<QtAndroidRelativeLayout>("android.widget", 0, 1, "RelativeLayout");
    qmlRegisterType<QtAndroidRelativeLayoutParams>();
    qmlRegisterType<QtAndroidScrollView>("android.widget", 0, 1, "ScrollView");
    qmlRegisterType<QtAndroidSeekBar>("android.widget", 0, 1, "SeekBar");
    qmlRegisterType<QtAndroidSpace>("android.widget", 0, 1, "Space");
    qmlRegisterType<QtAndroidSpinner>("android.widget", 0, 1, "Spinner");
    qmlRegisterType<QtAndroidSwitch>("android.widget", 0, 1, "Switch");
    qmlRegisterType<QtAndroidTabHost>("android.widget", 0, 1, "TabHost");
    qmlRegisterUncreatableType<QtAndroidTabSpec>("android.widget", 0, 1, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtAndroidTabWidget>("android.widget", 0, 1, "TabWidget");
    qmlRegisterType<QtAndroidTextView>("android.widget", 0, 1, "TextView");
    qmlRegisterType<QtAndroidToggleButton>("android.widget", 0, 1, "ToggleButton");
    qmlRegisterType<QtAndroidViewAnimator>("android.widget", 0, 1, "ViewAnimator");
    qmlRegisterType<QtAndroidViewFlipper>("android.widget", 0, 1, "ViewFlipper");
    qmlRegisterType<QtAndroidViewSwitcher>("android.widget", 0, 1, "ViewSwitcher");

    qmlRegisterType<QtAndroidDrawerLayout>("android.support.v4.widget", 0, 1, "DrawerLayout");

    qmlRegisterType<QtAndroidActionBarDrawerToggle>("android.support.v7.app", 0, 1, "ActionBarDrawerToggle");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
