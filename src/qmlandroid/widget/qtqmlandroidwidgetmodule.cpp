#include "qtqmlandroidwidgetmodule_p.h"

#include "qtqmlandroidarrayadapter_p.h"
#include "qtqmlandroidbutton_p.h"
#include "qtqmlandroidcalendarview_p.h"
#include "qtqmlandroidcheckbox_p.h"
#include "qtqmlandroiddatepicker_p.h"
#include "qtqmlandroidedittext_p.h"
#include "qtqmlandroidframelayout_p.h"
#include "qtqmlandroidframelayoutparams_p.h"
#include "qtqmlandroidimageview_p.h"
#include "qtqmlandroidlinearlayout_p.h"
#include "qtqmlandroidlinearlayoutparams_p.h"
#include "qtqmlandroidlistview_p.h"
#include "qtqmlandroidnumberpicker_p.h"
#include "qtqmlandroidpopupmenu_p.h"
#include "qtqmlandroidprogressbar_p.h"
#include "qtqmlandroidradiobutton_p.h"
#include "qtqmlandroidradiogroup_p.h"
#include "qtqmlandroidratingbar_p.h"
#include "qtqmlandroidrelativelayout_p.h"
#include "qtqmlandroidrelativelayoutparams_p.h"
#include "qtqmlandroidscrollview_p.h"
#include "qtqmlandroidsearchview_p.h"
#include "qtqmlandroidseekbar_p.h"
#include "qtqmlandroidspace_p.h"
#include "qtqmlandroidspinner_p.h"
#include "qtqmlandroidswitch_p.h"
#include "qtqmlandroidtabhost_p.h"
#include "qtqmlandroidtabspec_p.h"
#include "qtqmlandroidtabwidget_p.h"
#include "qtqmlandroidtextview_p.h"
#include "qtqmlandroidtimepicker_p.h"
#include "qtqmlandroidtoast_p.h"
#include "qtqmlandroidtogglebutton_p.h"
#include "qtqmlandroidviewanimator_p.h"
#include "qtqmlandroidviewflipper_p.h"
#include "qtqmlandroidviewswitcher_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerWidgetModule(const char *uri)
{
    qmlRegisterType<QtQmlAndroidArrayAdapter>(uri, 0, 21, "ArrayAdapter");
    qmlRegisterType<QtQmlAndroidBaseAdapter>();
    qmlRegisterType<QtQmlAndroidButton>(uri, 0, 21, "Button");
    qmlRegisterType<QtQmlAndroidCalendarView>(uri, 0, 21, "CalendarView");
    qmlRegisterType<QtQmlAndroidCheckBox>(uri, 0, 21, "CheckBox");
    qmlRegisterType<QtQmlAndroidDatePicker>(uri, 0, 21, "DatePicker");
    qmlRegisterType<QtQmlAndroidEditText>(uri, 0, 21, "EditText");
    qmlRegisterType<QtQmlAndroidFrameLayout>(uri, 0, 21, "FrameLayout");
    qmlRegisterType<QtQmlAndroidFrameLayoutParams>();
    qmlRegisterType<QtQmlAndroidImageView>(uri, 0, 21, "ImageView");
    qmlRegisterType<QtQmlAndroidLinearLayout>(uri, 0, 21, "LinearLayout");
    qmlRegisterType<QtQmlAndroidLinearLayoutParams>();
    qmlRegisterType<QtQmlAndroidListView>(uri, 0, 21, "ListView");
    qmlRegisterType<QtQmlAndroidNumberPicker>(uri, 0, 21, "NumberPicker");
    qmlRegisterType<QtQmlAndroidPopupMenu>(uri, 0, 21, "PopupMenu");
    qmlRegisterType<QtQmlAndroidProgressBar>(uri, 0, 21, "ProgressBar");
    qmlRegisterType<QtQmlAndroidRadioButton>(uri, 0, 21, "RadioButton");
    qmlRegisterType<QtQmlAndroidRadioGroup>(uri, 0, 21, "RadioGroup");
    qmlRegisterType<QtQmlAndroidRatingBar>(uri, 0, 21, "RatingBar");
    qmlRegisterType<QtQmlAndroidRelativeLayout>(uri, 0, 21, "RelativeLayout");
    qmlRegisterType<QtQmlAndroidRelativeLayoutParams>();
    qmlRegisterType<QtQmlAndroidScrollView>(uri, 0, 21, "ScrollView");
    qmlRegisterType<QtQmlAndroidSearchView>(uri, 0, 21, "SearchView");
    qmlRegisterType<QtQmlAndroidSeekBar>(uri, 0, 21, "SeekBar");
    qmlRegisterType<QtQmlAndroidSpace>(uri, 0, 21, "Space");
    qmlRegisterType<QtQmlAndroidSpinner>(uri, 0, 21, "Spinner");
    qmlRegisterType<QtQmlAndroidSwitch>(uri, 0, 21, "Switch");
    qmlRegisterType<QtQmlAndroidTabHost>(uri, 0, 21, "TabHost");
    qmlRegisterUncreatableType<QtQmlAndroidTabSpec>(uri, 0, 21, "TabSpec", "TabSpec is an attached property");
    qmlRegisterType<QtQmlAndroidTabWidget>(uri, 0, 21, "TabWidget");
    qmlRegisterType<QtQmlAndroidTextView>(uri, 0, 21, "TextView");
    qmlRegisterType<QtQmlAndroidTimePicker>(uri, 0, 21, "TimePicker");
    qmlRegisterType<QtQmlAndroidToast>(uri, 0, 21, "Toast");
    qmlRegisterType<QtQmlAndroidToggleButton>(uri, 0, 21, "ToggleButton");
    qmlRegisterType<QtQmlAndroidViewAnimator>(uri, 0, 21, "ViewAnimator");
    qmlRegisterType<QtQmlAndroidViewFlipper>(uri, 0, 21, "ViewFlipper");
    qmlRegisterType<QtQmlAndroidViewSwitcher>(uri, 0, 21, "ViewSwitcher");
}

}

QT_END_NAMESPACE
