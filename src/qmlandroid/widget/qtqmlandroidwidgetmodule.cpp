#include "qtqmlandroidwidgetmodule_p.h"

#include "qqmlandroidarrayadapter_p.h"
#include "qqmlandroidbutton_p.h"
#include "qqmlandroidcalendarview_p.h"
#include "qqmlandroidcheckbox_p.h"
#include "qqmlandroiddatepicker_p.h"
#include "qqmlandroidedittext_p.h"
#include "qqmlandroidframelayout_p.h"
#include "qqmlandroidframelayoutparams_p.h"
#include "qqmlandroidimageview_p.h"
#include "qqmlandroidlinearlayout_p.h"
#include "qqmlandroidlinearlayoutparams_p.h"
#include "qqmlandroidlistview_p.h"
#include "qqmlandroidnumberpicker_p.h"
#include "qqmlandroidpopupmenu_p.h"
#include "qqmlandroidprogressbar_p.h"
#include "qqmlandroidradiobutton_p.h"
#include "qqmlandroidradiogroup_p.h"
#include "qqmlandroidratingbar_p.h"
#include "qqmlandroidrelativelayout_p.h"
#include "qqmlandroidrelativelayoutparams_p.h"
#include "qqmlandroidscrollview_p.h"
#include "qqmlandroidsearchview_p.h"
#include "qqmlandroidseekbar_p.h"
#include "qqmlandroidspace_p.h"
#include "qqmlandroidspinner_p.h"
#include "qqmlandroidswitch_p.h"
#include "qqmlandroidtabhost_p.h"
#include "qqmlandroidtabspec_p.h"
#include "qqmlandroidtabwidget_p.h"
#include "qqmlandroidtextview_p.h"
#include "qqmlandroidtimepicker_p.h"
#include "qqmlandroidtoast_p.h"
#include "qqmlandroidtogglebutton_p.h"
#include "qqmlandroidviewanimator_p.h"
#include "qqmlandroidviewflipper_p.h"
#include "qqmlandroidviewswitcher_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerWidgetModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidArrayAdapter>(uri, 0, 21, "ArrayAdapter");
    qmlRegisterType<QQmlAndroidBaseAdapter>();
    qmlRegisterType<QQmlAndroidButton>(uri, 0, 21, "Button");
    qmlRegisterType<QQmlAndroidCalendarView>(uri, 0, 21, "CalendarView");
    qmlRegisterType<QQmlAndroidCheckBox>(uri, 0, 21, "CheckBox");
    qmlRegisterType<QQmlAndroidDatePicker>(uri, 0, 21, "DatePicker");
    qmlRegisterType<QQmlAndroidEditText>(uri, 0, 21, "EditText");
    qmlRegisterType<QQmlAndroidFrameLayout>(uri, 0, 21, "FrameLayout");
    qmlRegisterType<QQmlAndroidFrameLayoutParams>();
    qmlRegisterType<QQmlAndroidImageView>(uri, 0, 21, "ImageView");
    qmlRegisterType<QQmlAndroidLinearLayout>(uri, 0, 21, "LinearLayout");
    qmlRegisterType<QQmlAndroidLinearLayoutParams>();
    qmlRegisterType<QQmlAndroidListView>(uri, 0, 21, "ListView");
    qmlRegisterType<QQmlAndroidNumberPicker>(uri, 0, 21, "NumberPicker");
    qmlRegisterType<QQmlAndroidPopupMenu>(uri, 0, 21, "PopupMenu");
    qmlRegisterType<QQmlAndroidProgressBar>(uri, 0, 21, "ProgressBar");
    qmlRegisterType<QQmlAndroidRadioButton>(uri, 0, 21, "RadioButton");
    qmlRegisterType<QQmlAndroidRadioGroup>(uri, 0, 21, "RadioGroup");
    qmlRegisterType<QQmlAndroidRatingBar>(uri, 0, 21, "RatingBar");
    qmlRegisterType<QQmlAndroidRelativeLayout>(uri, 0, 21, "RelativeLayout");
    qmlRegisterType<QQmlAndroidRelativeLayoutParams>();
    qmlRegisterType<QQmlAndroidScrollView>(uri, 0, 21, "ScrollView");
    qmlRegisterType<QQmlAndroidSearchView>(uri, 0, 21, "SearchView");
    qmlRegisterType<QQmlAndroidSeekBar>(uri, 0, 21, "SeekBar");
    qmlRegisterType<QQmlAndroidSpace>(uri, 0, 21, "Space");
    qmlRegisterType<QQmlAndroidSpinner>(uri, 0, 21, "Spinner");
    qmlRegisterType<QQmlAndroidSwitch>(uri, 0, 21, "Switch");
    qmlRegisterType<QQmlAndroidTabHost>(uri, 0, 21, "TabHost");
    qmlRegisterUncreatableType<QQmlAndroidTabSpec>(uri, 0, 21, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QQmlAndroidTabWidget>(uri, 0, 21, "TabWidget");
    qmlRegisterType<QQmlAndroidTextView>(uri, 0, 21, "TextView");
    qmlRegisterType<QQmlAndroidTimePicker>(uri, 0, 21, "TimePicker");
    qmlRegisterType<QQmlAndroidToast>(uri, 0, 21, "Toast");
    qmlRegisterType<QQmlAndroidToggleButton>(uri, 0, 21, "ToggleButton");
    qmlRegisterType<QQmlAndroidViewAnimator>(uri, 0, 21, "ViewAnimator");
    qmlRegisterType<QQmlAndroidViewFlipper>(uri, 0, 21, "ViewFlipper");
    qmlRegisterType<QQmlAndroidViewSwitcher>(uri, 0, 21, "ViewSwitcher");
}

}

QT_END_NAMESPACE
