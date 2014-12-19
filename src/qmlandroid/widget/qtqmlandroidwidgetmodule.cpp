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
