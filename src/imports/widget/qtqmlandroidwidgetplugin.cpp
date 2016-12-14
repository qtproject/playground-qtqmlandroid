/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt QML Android module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>

#include <QtQmlAndroid/private/qnativeandroidarrayadapter_p.h>
#include <QtQmlAndroid/private/qnativeandroidbutton_p.h>
#include <QtQmlAndroid/private/qnativeandroidcalendarview_p.h>
#include <QtQmlAndroid/private/qnativeandroidcheckbox_p.h>
#include <QtQmlAndroid/private/qnativeandroiddatepicker_p.h>
#include <QtQmlAndroid/private/qnativeandroidedittext_p.h>
#include <QtQmlAndroid/private/qnativeandroidframelayout_p.h>
#include <QtQmlAndroid/private/qnativeandroidframelayoutparams_p.h>
#include <QtQmlAndroid/private/qnativeandroidimageview_p.h>
#include <QtQmlAndroid/private/qnativeandroidlinearlayout_p.h>
#include <QtQmlAndroid/private/qnativeandroidlinearlayoutparams_p.h>
#include <QtQmlAndroid/private/qnativeandroidlistview_p.h>
#include <QtQmlAndroid/private/qnativeandroidnumberpicker_p.h>
#include <QtQmlAndroid/private/qnativeandroidpopupmenu_p.h>
#include <QtQmlAndroid/private/qnativeandroidprogressbar_p.h>
#include <QtQmlAndroid/private/qnativeandroidradiobutton_p.h>
#include <QtQmlAndroid/private/qnativeandroidradiogroup_p.h>
#include <QtQmlAndroid/private/qnativeandroidratingbar_p.h>
#include <QtQmlAndroid/private/qnativeandroidrelativelayout_p.h>
#include <QtQmlAndroid/private/qnativeandroidrelativelayoutparams_p.h>
#include <QtQmlAndroid/private/qnativeandroidscrollview_p.h>
#include <QtQmlAndroid/private/qnativeandroidsearchview_p.h>
#include <QtQmlAndroid/private/qnativeandroidseekbar_p.h>
#include <QtQmlAndroid/private/qnativeandroidspace_p.h>
#include <QtQmlAndroid/private/qnativeandroidspinner_p.h>
#include <QtQmlAndroid/private/qnativeandroidswitch_p.h>
#include <QtQmlAndroid/private/qnativeandroidtabhost_p.h>
#include <QtQmlAndroid/private/qnativeandroidtabspec_p.h>
#include <QtQmlAndroid/private/qnativeandroidtabwidget_p.h>
#include <QtQmlAndroid/private/qnativeandroidtextview_p.h>
#include <QtQmlAndroid/private/qnativeandroidtimepicker_p.h>
#include <QtQmlAndroid/private/qnativeandroidtoast_p.h>
#include <QtQmlAndroid/private/qnativeandroidtogglebutton_p.h>
#include <QtQmlAndroid/private/qnativeandroidviewanimator_p.h>
#include <QtQmlAndroid/private/qnativeandroidviewflipper_p.h>
#include <QtQmlAndroid/private/qnativeandroidviewswitcher_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidWidgetPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri) override;
};

void QtQmlAndroidWidgetPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<QNativeAndroidArrayAdapter>(uri, 0, 21, "ArrayAdapter");
    qmlRegisterType<QNativeAndroidBaseAdapter>();
    qmlRegisterType<QNativeAndroidButton>(uri, 0, 21, "Button");
    qmlRegisterType<QNativeAndroidCalendarView>(uri, 0, 21, "CalendarView");
    qmlRegisterType<QNativeAndroidCheckBox>(uri, 0, 21, "CheckBox");
    qmlRegisterType<QNativeAndroidDatePicker>(uri, 0, 21, "DatePicker");
    qmlRegisterType<QNativeAndroidEditText>(uri, 0, 21, "EditText");
    qmlRegisterType<QNativeAndroidFrameLayout>(uri, 0, 21, "FrameLayout");
    qmlRegisterType<QNativeAndroidFrameLayoutParams>();
    qmlRegisterType<QNativeAndroidImageView>(uri, 0, 21, "ImageView");
    qmlRegisterType<QNativeAndroidLinearLayout>(uri, 0, 21, "LinearLayout");
    qmlRegisterType<QNativeAndroidLinearLayoutParams>();
    qmlRegisterType<QNativeAndroidListView>(uri, 0, 21, "ListView");
    qmlRegisterType<QNativeAndroidNumberPicker>(uri, 0, 21, "NumberPicker");
    qmlRegisterType<QNativeAndroidPopupMenu>(uri, 0, 21, "PopupMenu");
    qmlRegisterType<QNativeAndroidProgressBar>(uri, 0, 21, "ProgressBar");
    qmlRegisterType<QNativeAndroidRadioButton>(uri, 0, 21, "RadioButton");
    qmlRegisterType<QNativeAndroidRadioGroup>(uri, 0, 21, "RadioGroup");
    qmlRegisterType<QNativeAndroidRatingBar>(uri, 0, 21, "RatingBar");
    qmlRegisterType<QNativeAndroidRelativeLayout>(uri, 0, 21, "RelativeLayout");
    qmlRegisterType<QNativeAndroidRelativeLayoutParams>();
    qmlRegisterType<QNativeAndroidScrollView>(uri, 0, 21, "ScrollView");
    qmlRegisterType<QNativeAndroidSearchView>(uri, 0, 21, "SearchView");
    qmlRegisterType<QNativeAndroidSeekBar>(uri, 0, 21, "SeekBar");
    qmlRegisterType<QNativeAndroidSpace>(uri, 0, 21, "Space");
    qmlRegisterType<QNativeAndroidSpinner>(uri, 0, 21, "Spinner");
    qmlRegisterType<QNativeAndroidSwitch>(uri, 0, 21, "Switch");
    qmlRegisterType<QNativeAndroidTabHost>(uri, 0, 21, "TabHost");
    qmlRegisterUncreatableType<QNativeAndroidTabSpec>(uri, 0, 21, "TabSpec", QStringLiteral("TabSpec is an attached property"));
    qmlRegisterType<QNativeAndroidTabWidget>(uri, 0, 21, "TabWidget");
    qmlRegisterType<QNativeAndroidTextView>(uri, 0, 21, "TextView");
    qmlRegisterType<QNativeAndroidTimePicker>(uri, 0, 21, "TimePicker");
    qmlRegisterType<QNativeAndroidToast>(uri, 0, 21, "Toast");
    qmlRegisterType<QNativeAndroidToggleButton>(uri, 0, 21, "ToggleButton");
    qmlRegisterType<QNativeAndroidViewAnimator>(uri, 0, 21, "ViewAnimator");
    qmlRegisterType<QNativeAndroidViewFlipper>(uri, 0, 21, "ViewFlipper");
    qmlRegisterType<QNativeAndroidViewSwitcher>(uri, 0, 21, "ViewSwitcher");
}

QT_END_NAMESPACE

#include "qtqmlandroidwidgetplugin.moc"
