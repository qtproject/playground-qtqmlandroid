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
#include "qtandroidalphaanimation_p.h"
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
#include "qtandroidtranslateanimation_p.h"

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

    qmlRegisterType<QtAndroidActionBar>("android.app", 0, 21, "ActionBar");
    qmlRegisterType<QtAndroidActivity>("android.app", 0, 21, "Activity");
    qmlRegisterType<QtAndroidAlertDialog>("android.app", 0, 21, "AlertDialog");
    qmlRegisterType<QtAndroidDialog>("android.app", 0, 21, "Dialog");
    qmlRegisterType<QtAndroidService>("android.app", 0, 21, "Service");

    qmlRegisterType<QtAndroidContext>();

    qmlRegisterSingletonType<QtAndroidColor>("android.graphics", 0, 21, "Color", QtAndroidColor::provider);
    qmlRegisterType<QtAndroidColorDrawable>("android.graphics.drawable", 0, 21, "ColorDrawable");
    qmlRegisterType<QtAndroidDrawable>("android.graphics.drawable", 0, 21, "Drawable");

    qmlRegisterSingletonType<QtAndroidR>("android.R", 0, 21, "R", QtAndroidR::provider);

    qmlRegisterUncreatableType<QtAndroidGravity>("android.view", 0, 21, "Gravity", "Gravity is an enum");
    qmlRegisterUncreatableType<QtAndroidLayoutParams>("android.view", 0, 21, "Layout", "Layout is an attached property");
    qmlRegisterType<QtAndroidMenu>("android.view", 0, 21, "Menu");
    qmlRegisterType<QtAndroidMenuItem>("android.view", 0, 21, "MenuItem");
    qmlRegisterType<QtAndroidView>("android.view", 0, 21, "View");
    qmlRegisterType<QtAndroidViewGroup>("android.view", 0, 21, "ViewGroup");
    qmlRegisterType<QtAndroidWindow>();

    qmlRegisterType<QtAndroidAccelerateDecelerateInterpolator>("android.view.animation", 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QtAndroidAccelerateInterpolator>("android.view.animation", 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QtAndroidAlphaAnimation>("android.view.animation", 0, 21, "AlphaAnimation");
    qmlRegisterType<QtAndroidAnimation>("android.view.animation", 0, 21, "Animation");
    qmlRegisterType<QtAndroidAnimationSet>("android.view.animation", 0, 21, "AnimationSet");
    qmlRegisterType<QtAndroidAnticipateInterpolator>("android.view.animation", 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QtAndroidAnticipateOvershootInterpolator>("android.view.animation", 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QtAndroidBounceInterpolator>("android.view.animation", 0, 21, "BounceInterpolator");
    qmlRegisterType<QtAndroidCycleInterpolator>("android.view.animation", 0, 21, "CycleInterpolator");
    qmlRegisterType<QtAndroidDecelerateInterpolator>("android.view.animation", 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QtAndroidInterpolator>("android.view", 0, 21, "Interpolator", "Interpolator is abstract");
    qmlRegisterType<QtAndroidLinearInterpolator>("android.view.animation", 0, 21, "LinearInterpolator");
    qmlRegisterType<QtAndroidOvershootInterpolator>("android.view.animation", 0, 21, "OvershootInterpolator");
    qmlRegisterType<QtAndroidPathInterpolator>("android.view.animation", 0, 21, "PathInterpolator");
    qmlRegisterType<QtAndroidRotateAnimation>("android.view.animation", 0, 21, "RotateAnimation");
    qmlRegisterType<QtAndroidScaleAnimation>("android.view.animation", 0, 21, "ScaleAnimation");
    qmlRegisterType<QtAndroidTranslateAnimation>("android.view.animation", 0, 21, "TranslateAnimation");

    qmlRegisterType<QtAndroidArrayAdapter>("android.widget", 0, 21, "ArrayAdapter");
    qmlRegisterType<QtAndroidBaseAdapter>();
    qmlRegisterType<QtAndroidButton>("android.widget", 0, 21, "Button");
    qmlRegisterType<QtAndroidCalendarView>("android.widget", 0, 21, "CalendarView");
    qmlRegisterType<QtAndroidCheckBox>("android.widget", 0, 21, "CheckBox");
    qmlRegisterType<QtAndroidDatePicker>("android.widget", 0, 21, "DatePicker");
    qmlRegisterType<QtAndroidEditText>("android.widget", 0, 21, "EditText");
    qmlRegisterType<QtAndroidFrameLayout>("android.widget", 0, 21, "FrameLayout");
    qmlRegisterType<QtAndroidFrameLayoutParams>();
    qmlRegisterType<QtAndroidImageView>("android.widget", 0, 21, "ImageView");
    qmlRegisterType<QtAndroidLinearLayout>("android.widget", 0, 21, "LinearLayout");
    qmlRegisterType<QtAndroidLinearLayoutParams>();
    qmlRegisterType<QtAndroidListView>("android.widget", 0, 21, "ListView");
    qmlRegisterType<QtAndroidNumberPicker>("android.widget", 0, 21, "NumberPicker");
    qmlRegisterType<QtAndroidPopupMenu>("android.widget", 0, 21, "PopupMenu");
    qmlRegisterType<QtAndroidProgressBar>("android.widget", 0, 21, "ProgressBar");
    qmlRegisterType<QtAndroidRadioButton>("android.widget", 0, 21, "RadioButton");
    qmlRegisterType<QtAndroidRadioGroup>("android.widget", 0, 21, "RadioGroup");
    qmlRegisterType<QtAndroidRatingBar>("android.widget", 0, 21, "RatingBar");
    qmlRegisterType<QtAndroidRelativeLayout>("android.widget", 0, 21, "RelativeLayout");
    qmlRegisterType<QtAndroidRelativeLayoutParams>();
    qmlRegisterType<QtAndroidScrollView>("android.widget", 0, 21, "ScrollView");
    qmlRegisterType<QtAndroidSearchView>("android.widget", 0, 21, "SearchView");
    qmlRegisterType<QtAndroidSeekBar>("android.widget", 0, 21, "SeekBar");
    qmlRegisterType<QtAndroidSpace>("android.widget", 0, 21, "Space");
    qmlRegisterType<QtAndroidSpinner>("android.widget", 0, 21, "Spinner");
    qmlRegisterType<QtAndroidSwitch>("android.widget", 0, 21, "Switch");
    qmlRegisterType<QtAndroidTabHost>("android.widget", 0, 21, "TabHost");
    qmlRegisterUncreatableType<QtAndroidTabSpec>("android.widget", 0, 21, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtAndroidTabWidget>("android.widget", 0, 21, "TabWidget");
    qmlRegisterType<QtAndroidTextView>("android.widget", 0, 21, "TextView");
    qmlRegisterType<QtAndroidTimePicker>("android.widget", 0, 21, "TimePicker");
    qmlRegisterType<QtAndroidToast>("android.widget", 0, 21, "Toast");
    qmlRegisterType<QtAndroidToggleButton>("android.widget", 0, 21, "ToggleButton");
    qmlRegisterType<QtAndroidViewAnimator>("android.widget", 0, 21, "ViewAnimator");
    qmlRegisterType<QtAndroidViewFlipper>("android.widget", 0, 21, "ViewFlipper");
    qmlRegisterType<QtAndroidViewSwitcher>("android.widget", 0, 21, "ViewSwitcher");

    qmlRegisterType<QtAndroidDrawerLayout>("android.support.v4.widget", 0, 21, "DrawerLayout");
    qmlRegisterType<QtAndroidSwipeRefreshLayout>("android.support.v4.widget", 0, 21, "SwipeRefreshLayout");

    qmlRegisterType<QtAndroidActionBarDrawerToggle>("android.support.v7.app", 0, 21, "ActionBarDrawerToggle");
    qmlRegisterType<QtAndroidCardView>("android.support.v7.widget", 0, 21, "CardView");
    qmlRegisterType<QtAndroidRecyclerAdapter>("android.support.v7.widget", 0, 21, "RecyclerAdapter");
    qmlRegisterType<QtAndroidRecyclerView>("android.support.v7.widget", 0, 21, "RecyclerView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
