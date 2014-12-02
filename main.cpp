#include <QtQml>

#include "qtdroidactionbar_p.h"
#include "qtdroidactivity_p.h"

#include "qtdroidcontext_p.h"

#include "qtdroidcolor_p.h"

#include "qtdroidgravity_p.h"
#include "qtdroidlayoutparams_p.h"
#include "qtdroidmenuitem_p.h"
#include "qtdroidview_p.h"
#include "qtdroidviewgroup_p.h"

#include "qtdroidarrayadapter_p.h"
#include "qtdroidbutton_p.h"
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

    qmlRegisterType<QtDroidActionBar>("qtdroid.app", 0, 1, "ActionBar");
    qmlRegisterType<QtDroidActivity>("qtdroid.app", 0, 1, "Activity");

    qmlRegisterType<QtDroidContext>();

    qmlRegisterSingletonType<QtDroidColor>("qtdroid.graphics", 0, 1, "Color", QtDroidColor::provider);

    qmlRegisterUncreatableType<QtDroidGravity>("qtdroid.view", 0, 1, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtDroidLayoutParams>("qtdroid.view", 0, 1, "Layout", "Layout is an attached property");
    qmlRegisterType<QtDroidMenuItem>("qtdroid.view", 0, 1, "MenuItem");
    qmlRegisterType<QtDroidView>();
    qmlRegisterType<QtDroidViewGroup>();

    qmlRegisterType<QtDroidArrayAdapter>("qtdroid.widget", 0, 1, "ArrayAdapter");
    qmlRegisterType<QtDroidBaseAdapter>();
    qmlRegisterType<QtDroidButton>("qtdroid.widget", 0, 1, "Button");
    qmlRegisterType<QtDroidCheckBox>("qtdroid.widget", 0, 1, "CheckBox");
    qmlRegisterType<QtDroidEditText>("qtdroid.widget", 0, 1, "EditText");
    qmlRegisterType<QtDroidFrameLayout>("qtdroid.widget", 0, 1, "FrameLayout");
    qmlRegisterType<QtDroidFrameLayoutParams>();
    qmlRegisterType<QtDroidLinearLayout>("qtdroid.widget", 0, 1, "LinearLayout");
    qmlRegisterType<QtDroidLinearLayoutParams>();
    qmlRegisterType<QtDroidListView>("qtdroid.widget", 0, 1, "ListView");
    qmlRegisterType<QtDroidPopupMenu>("qtdroid.widget", 0, 1, "PopupMenu");
    qmlRegisterType<QtDroidProgressBar>("qtdroid.widget", 0, 1, "ProgressBar");
    qmlRegisterType<QtDroidRadioButton>("qtdroid.widget", 0, 1, "RadioButton");
    qmlRegisterType<QtDroidRadioGroup>("qtdroid.widget", 0, 1, "RadioGroup");
    qmlRegisterType<QtDroidRelativeLayout>("qtdroid.widget", 0, 1, "RelativeLayout");
    qmlRegisterType<QtDroidRelativeLayoutParams>();
    qmlRegisterType<QtDroidScrollView>("qtdroid.widget", 0, 1, "ScrollView");
    qmlRegisterType<QtDroidSeekBar>("qtdroid.widget", 0, 1, "SeekBar");
    qmlRegisterType<QtDroidSpace>("qtdroid.widget", 0, 1, "Space");
    qmlRegisterType<QtDroidSpinner>("qtdroid.widget", 0, 1, "Spinner");
    qmlRegisterType<QtDroidSwitch>("qtdroid.widget", 0, 1, "Switch");
    qmlRegisterType<QtDroidTextView>("qtdroid.widget", 0, 1, "TextView");
    qmlRegisterType<QtDroidToggleButton>("qtdroid.widget", 0, 1, "ToggleButton");
    qmlRegisterType<QtDroidViewAnimator>("qtdroid.widget", 0, 1, "ViewAnimator");
    qmlRegisterType<QtDroidViewFlipper>("qtdroid.widget", 0, 1, "ViewFlipper");
    qmlRegisterType<QtDroidViewSwitcher>("qtdroid.widget", 0, 1, "ViewSwitcher");

    qmlRegisterType<QtDroidDrawerLayout>("qtdroid.support.v4.widget", 0, 1, "DrawerLayout");

    qmlRegisterType<QtDroidActionBarDrawerToggle>("qtdroid.support.v7.app", 0, 1, "ActionBarDrawerToggle");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
