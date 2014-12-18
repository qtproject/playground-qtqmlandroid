#include "qtandroidwidgetmodule_p.h"

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

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtAndroid {

void registerWidgetModule(const char *uri)
{
    qmlRegisterType<QtAndroidArrayAdapter>(uri, 0, 21, "ArrayAdapter");
    qmlRegisterType<QtAndroidBaseAdapter>();
    qmlRegisterType<QtAndroidButton>(uri, 0, 21, "Button");
    qmlRegisterType<QtAndroidCalendarView>(uri, 0, 21, "CalendarView");
    qmlRegisterType<QtAndroidCheckBox>(uri, 0, 21, "CheckBox");
    qmlRegisterType<QtAndroidDatePicker>(uri, 0, 21, "DatePicker");
    qmlRegisterType<QtAndroidEditText>(uri, 0, 21, "EditText");
    qmlRegisterType<QtAndroidFrameLayout>(uri, 0, 21, "FrameLayout");
    qmlRegisterType<QtAndroidFrameLayoutParams>();
    qmlRegisterType<QtAndroidImageView>(uri, 0, 21, "ImageView");
    qmlRegisterType<QtAndroidLinearLayout>(uri, 0, 21, "LinearLayout");
    qmlRegisterType<QtAndroidLinearLayoutParams>();
    qmlRegisterType<QtAndroidListView>(uri, 0, 21, "ListView");
    qmlRegisterType<QtAndroidNumberPicker>(uri, 0, 21, "NumberPicker");
    qmlRegisterType<QtAndroidPopupMenu>(uri, 0, 21, "PopupMenu");
    qmlRegisterType<QtAndroidProgressBar>(uri, 0, 21, "ProgressBar");
    qmlRegisterType<QtAndroidRadioButton>(uri, 0, 21, "RadioButton");
    qmlRegisterType<QtAndroidRadioGroup>(uri, 0, 21, "RadioGroup");
    qmlRegisterType<QtAndroidRatingBar>(uri, 0, 21, "RatingBar");
    qmlRegisterType<QtAndroidRelativeLayout>(uri, 0, 21, "RelativeLayout");
    qmlRegisterType<QtAndroidRelativeLayoutParams>();
    qmlRegisterType<QtAndroidScrollView>(uri, 0, 21, "ScrollView");
    qmlRegisterType<QtAndroidSearchView>(uri, 0, 21, "SearchView");
    qmlRegisterType<QtAndroidSeekBar>(uri, 0, 21, "SeekBar");
    qmlRegisterType<QtAndroidSpace>(uri, 0, 21, "Space");
    qmlRegisterType<QtAndroidSpinner>(uri, 0, 21, "Spinner");
    qmlRegisterType<QtAndroidSwitch>(uri, 0, 21, "Switch");
    qmlRegisterType<QtAndroidTabHost>(uri, 0, 21, "TabHost");
    qmlRegisterUncreatableType<QtAndroidTabSpec>(uri, 0, 21, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtAndroidTabWidget>(uri, 0, 21, "TabWidget");
    qmlRegisterType<QtAndroidTextView>(uri, 0, 21, "TextView");
    qmlRegisterType<QtAndroidTimePicker>(uri, 0, 21, "TimePicker");
    qmlRegisterType<QtAndroidToast>(uri, 0, 21, "Toast");
    qmlRegisterType<QtAndroidToggleButton>(uri, 0, 21, "ToggleButton");
    qmlRegisterType<QtAndroidViewAnimator>(uri, 0, 21, "ViewAnimator");
    qmlRegisterType<QtAndroidViewFlipper>(uri, 0, 21, "ViewFlipper");
    qmlRegisterType<QtAndroidViewSwitcher>(uri, 0, 21, "ViewSwitcher");
}

}

QT_END_NAMESPACE
