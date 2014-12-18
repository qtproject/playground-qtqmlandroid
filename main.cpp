#include <QtQml>

#include "qtandroidactionbar_p.h"
#include "qtandroidactivity_p.h"
#include "qtandroidalertdialog_p.h"
#include "qtandroiddialog_p.h"
#include "qtandroidservice_p.h"

#include "qtandroidcontext_p.h"

#include "qtandroidcolor_p.h"
#include "qtandroidcolordrawable_p.h"
#include "qtandroiddrawable_p.h"

#include "qtandroidr_p.h"

#include "qtandroidgravity_p.h"
#include "qtandroidlayoutparams_p.h"
#include "qtandroidmenu_p.h"
#include "qtandroidmenuitem_p.h"
#include "qtandroidview_p.h"
#include "qtandroidviewgroup_p.h"
#include "qtandroidwindow_p.h"

#include "qtandroidacceleratedecelerateinterpolator_p.h"
#include "qtandroidaccelerateinterpolator_p.h"
#include "qtandroidanimation_p.h"
#include "qtandroidanimationset_p.h"
#include "qtandroidanticipateinterpolator_p.h"
#include "qtandroidanticipateovershootinterpolator_p.h"
#include "qtandroidbounceinterpolator_p.h"
#include "qtandroidcycleinterpolator_p.h"
#include "qtandroiddecelerateinterpolator_p.h"
#include "qtandroidlinearinterpolator_p.h"
#include "qtandroidovershootinterpolator_p.h"
#include "qtandroidpathinterpolator_p.h"
#include "qtandroidrotateanimation_p.h"
#include "qtandroidscaleanimation_p.h"

#include "qtandroidarrayadapter_p.h"
#include "qtandroidbutton_p.h"
#include "qtandroidcalendarview_p.h"
#include "qtandroidcheckbox_p.h"
#include "qtandroiddatepicker_p.h"
#include "qtandroidedittext_p.h"
#include "qtandroidframelayout_p.h"
#include "qtandroidframelayoutparams_p.h"
#include "qtandroidimageview_p.h"
#include "qtandroidlinearlayout_p.h"
#include "qtandroidlinearlayoutparams_p.h"
#include "qtandroidlistview_p.h"
#include "qtandroidnumberpicker_p.h"
#include "qtandroidpopupmenu_p.h"
#include "qtandroidprogressbar_p.h"
#include "qtandroidradiobutton_p.h"
#include "qtandroidradiogroup_p.h"
#include "qtandroidratingbar_p.h"
#include "qtandroidrelativelayout_p.h"
#include "qtandroidrelativelayoutparams_p.h"
#include "qtandroidscrollview_p.h"
#include "qtandroidsearchview_p.h"
#include "qtandroidseekbar_p.h"
#include "qtandroidspace_p.h"
#include "qtandroidspinner_p.h"
#include "qtandroidswitch_p.h"
#include "qtandroidtabhost_p.h"
#include "qtandroidtabspec_p.h"
#include "qtandroidtabwidget_p.h"
#include "qtandroidtextview_p.h"
#include "qtandroidtimepicker_p.h"
#include "qtandroidtoast_p.h"
#include "qtandroidtogglebutton_p.h"
#include "qtandroidviewanimator_p.h"
#include "qtandroidviewflipper_p.h"
#include "qtandroidviewswitcher_p.h"

#include "qtandroiddrawerlayout_p.h"
#include "qtandroidswiperefreshlayout_p.h"

#include "qtandroidactionbardrawertoggle_p.h"
#include "qtandroidcardview_p.h"
#include "qtandroidrecycleradapter_p.h"
#include "qtandroidrecyclerview_p.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qRegisterMetaType<QQmlPropertyMap *>();

    qmlRegisterType<QtAndroidActionBar>("android.app", 21, 0, "ActionBar");
    qmlRegisterType<QtAndroidActivity>("android.app", 21, 0, "Activity");
    qmlRegisterType<QtAndroidAlertDialog>("android.app", 21, 0, "AlertDialog");
    qmlRegisterType<QtAndroidDialog>("android.app", 21, 0, "Dialog");
    qmlRegisterType<QtAndroidService>("android.app", 21, 0, "Service");

    qmlRegisterType<QtAndroidContext>();

    qmlRegisterSingletonType<QtAndroidColor>("android.graphics", 21, 0, "Color", QtAndroidColor::provider);
    qmlRegisterType<QtAndroidColorDrawable>("android.graphics.drawable", 21, 0, "ColorDrawable");
    qmlRegisterType<QtAndroidDrawable>("android.graphics.drawable", 21, 0, "Drawable");

    qmlRegisterSingletonType<QtAndroidR>("android.R", 21, 0, "R", QtAndroidR::provider);

    qmlRegisterUncreatableType<QtAndroidGravity>("android.view", 21, 0, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>("android.view", 21, 0, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>("android.view", 21, 0, "Menu");
    qmlRegisterType<QtAndroidMenuItem>("android.view", 21, 0, "MenuItem");
    qmlRegisterType<QtAndroidView>("android.view", 21, 0, "View");
    qmlRegisterType<QtAndroidViewGroup>("android.view", 21, 0, "ViewGroup");
    qmlRegisterType<QtAndroidWindow>();

    qmlRegisterType<QtAndroidAccelerateDecelerateInterpolator>("android.view.animation", 21, 0, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QtAndroidAccelerateInterpolator>("android.view.animation", 21, 0, "AccelerateInterpolator");
    qmlRegisterType<QtAndroidAnimation>("android.view.animation", 21, 0, "Animation");
    qmlRegisterType<QtAndroidAnimationSet>("android.view.animation", 21, 0, "AnimationSet");
    qmlRegisterType<QtAndroidAnticipateInterpolator>("android.view.animation", 21, 0, "AnticipateInterpolator");
    qmlRegisterType<QtAndroidAnticipateOvershootInterpolator>("android.view.animation", 21, 0, "AnticipateOvershootInterpolator");
    qmlRegisterType<QtAndroidBounceInterpolator>("android.view.animation", 21, 0, "BounceInterpolator");
    qmlRegisterType<QtAndroidCycleInterpolator>("android.view.animation", 21, 0, "CycleInterpolator");
    qmlRegisterType<QtAndroidDecelerateInterpolator>("android.view.animation", 21, 0, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QtAndroidInterpolator>("android.view", 21, 0, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QtAndroidLinearInterpolator>("android.view.animation", 21, 0, "LinearInterpolator");
    qmlRegisterType<QtAndroidOvershootInterpolator>("android.view.animation", 21, 0, "OvershootInterpolator");
    qmlRegisterType<QtAndroidPathInterpolator>("android.view.animation", 21, 0, "PathInterpolator");
    qmlRegisterType<QtAndroidRotateAnimation>("android.view.animation", 21, 0, "RotateAnimation");
    qmlRegisterType<QtAndroidScaleAnimation>("android.view.animation", 21, 0, "ScaleAnimation");

    qmlRegisterType<QtAndroidArrayAdapter>("android.widget", 21, 0, "ArrayAdapter");
    qmlRegisterType<QtAndroidBaseAdapter>();
    qmlRegisterType<QtAndroidButton>("android.widget", 21, 0, "Button");
    qmlRegisterType<QtAndroidCalendarView>("android.widget", 21, 0, "CalendarView");
    qmlRegisterType<QtAndroidCheckBox>("android.widget", 21, 0, "CheckBox");
    qmlRegisterType<QtAndroidDatePicker>("android.widget", 21, 0, "DatePicker");
    qmlRegisterType<QtAndroidEditText>("android.widget", 21, 0, "EditText");
    qmlRegisterType<QtAndroidFrameLayout>("android.widget", 21, 0, "FrameLayout");
    qmlRegisterType<QtAndroidFrameLayoutParams>();
    qmlRegisterType<QtAndroidImageView>("android.widget", 21, 0, "ImageView");
    qmlRegisterType<QtAndroidLinearLayout>("android.widget", 21, 0, "LinearLayout");
    qmlRegisterType<QtAndroidLinearLayoutParams>();
    qmlRegisterType<QtAndroidListView>("android.widget", 21, 0, "ListView");
    qmlRegisterType<QtAndroidNumberPicker>("android.widget", 21, 0, "NumberPicker");
    qmlRegisterType<QtAndroidPopupMenu>("android.widget", 21, 0, "PopupMenu");
    qmlRegisterType<QtAndroidProgressBar>("android.widget", 21, 0, "ProgressBar");
    qmlRegisterType<QtAndroidRadioButton>("android.widget", 21, 0, "RadioButton");
    qmlRegisterType<QtAndroidRadioGroup>("android.widget", 21, 0, "RadioGroup");
    qmlRegisterType<QtAndroidRatingBar>("android.widget", 21, 0, "RatingBar");
    qmlRegisterType<QtAndroidRelativeLayout>("android.widget", 21, 0, "RelativeLayout");
    qmlRegisterType<QtAndroidRelativeLayoutParams>();
    qmlRegisterType<QtAndroidScrollView>("android.widget", 21, 0, "ScrollView");
    qmlRegisterType<QtAndroidSearchView>("android.widget", 21, 0, "SearchView");
    qmlRegisterType<QtAndroidSeekBar>("android.widget", 21, 0, "SeekBar");
    qmlRegisterType<QtAndroidSpace>("android.widget", 21, 0, "Space");
    qmlRegisterType<QtAndroidSpinner>("android.widget", 21, 0, "Spinner");
    qmlRegisterType<QtAndroidSwitch>("android.widget", 21, 0, "Switch");
    qmlRegisterType<QtAndroidTabHost>("android.widget", 21, 0, "TabHost");
    qmlRegisterUncreatableType<QtAndroidTabSpec>("android.widget", 21, 0, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtAndroidTabWidget>("android.widget", 21, 0, "TabWidget");
    qmlRegisterType<QtAndroidTextView>("android.widget", 21, 0, "TextView");
    qmlRegisterType<QtAndroidTimePicker>("android.widget", 21, 0, "TimePicker");
    qmlRegisterType<QtAndroidToast>("android.widget", 21, 0, "Toast");
    qmlRegisterType<QtAndroidToggleButton>("android.widget", 21, 0, "ToggleButton");
    qmlRegisterType<QtAndroidViewAnimator>("android.widget", 21, 0, "ViewAnimator");
    qmlRegisterType<QtAndroidViewFlipper>("android.widget", 21, 0, "ViewFlipper");
    qmlRegisterType<QtAndroidViewSwitcher>("android.widget", 21, 0, "ViewSwitcher");

    qmlRegisterType<QtAndroidDrawerLayout>("android.support.v4.widget", 21, 0, "DrawerLayout");
    qmlRegisterType<QtAndroidSwipeRefreshLayout>("android.support.v4.widget", 21, 0, "SwipeRefreshLayout");

    qmlRegisterType<QtAndroidActionBarDrawerToggle>("android.support.v7.app", 21, 0, "ActionBarDrawerToggle");
    qmlRegisterType<QtAndroidCardView>("android.support.v7.widget", 21, 0, "CardView");
    qmlRegisterType<QtAndroidRecyclerAdapter>("android.support.v7.widget", 21, 0, "RecyclerAdapter");
    qmlRegisterType<QtAndroidRecyclerView>("android.support.v7.widget", 21, 0, "RecyclerView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
