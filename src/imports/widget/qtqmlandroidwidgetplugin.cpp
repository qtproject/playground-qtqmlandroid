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

#include <QtQmlAndroid/private/qqmlandroidarrayadapter_p.h>
#include <QtQmlAndroid/private/qqmlandroidbutton_p.h>
#include <QtQmlAndroid/private/qqmlandroidcalendarview_p.h>
#include <QtQmlAndroid/private/qqmlandroidcheckbox_p.h>
#include <QtQmlAndroid/private/qqmlandroiddatepicker_p.h>
#include <QtQmlAndroid/private/qqmlandroidedittext_p.h>
#include <QtQmlAndroid/private/qqmlandroidframelayout_p.h>
#include <QtQmlAndroid/private/qqmlandroidframelayoutparams_p.h>
#include <QtQmlAndroid/private/qqmlandroidimageview_p.h>
#include <QtQmlAndroid/private/qqmlandroidlinearlayout_p.h>
#include <QtQmlAndroid/private/qqmlandroidlinearlayoutparams_p.h>
#include <QtQmlAndroid/private/qqmlandroidlistview_p.h>
#include <QtQmlAndroid/private/qqmlandroidnumberpicker_p.h>
#include <QtQmlAndroid/private/qqmlandroidpopupmenu_p.h>
#include <QtQmlAndroid/private/qqmlandroidprogressbar_p.h>
#include <QtQmlAndroid/private/qqmlandroidradiobutton_p.h>
#include <QtQmlAndroid/private/qqmlandroidradiogroup_p.h>
#include <QtQmlAndroid/private/qqmlandroidratingbar_p.h>
#include <QtQmlAndroid/private/qqmlandroidrelativelayout_p.h>
#include <QtQmlAndroid/private/qqmlandroidrelativelayoutparams_p.h>
#include <QtQmlAndroid/private/qqmlandroidscrollview_p.h>
#include <QtQmlAndroid/private/qqmlandroidsearchview_p.h>
#include <QtQmlAndroid/private/qqmlandroidseekbar_p.h>
#include <QtQmlAndroid/private/qqmlandroidspace_p.h>
#include <QtQmlAndroid/private/qqmlandroidspinner_p.h>
#include <QtQmlAndroid/private/qqmlandroidswitch_p.h>
#include <QtQmlAndroid/private/qqmlandroidtabhost_p.h>
#include <QtQmlAndroid/private/qqmlandroidtabspec_p.h>
#include <QtQmlAndroid/private/qqmlandroidtabwidget_p.h>
#include <QtQmlAndroid/private/qqmlandroidtextview_p.h>
#include <QtQmlAndroid/private/qqmlandroidtimepicker_p.h>
#include <QtQmlAndroid/private/qqmlandroidtoast_p.h>
#include <QtQmlAndroid/private/qqmlandroidtogglebutton_p.h>
#include <QtQmlAndroid/private/qqmlandroidviewanimator_p.h>
#include <QtQmlAndroid/private/qqmlandroidviewflipper_p.h>
#include <QtQmlAndroid/private/qqmlandroidviewswitcher_p.h>

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
    qmlRegisterUncreatableType<QQmlAndroidTabSpec>(uri, 0, 21, "TabSpec", QStringLiteral("TabSpec is an attached property"));
    qmlRegisterType<QQmlAndroidTabWidget>(uri, 0, 21, "TabWidget");
    qmlRegisterType<QQmlAndroidTextView>(uri, 0, 21, "TextView");
    qmlRegisterType<QQmlAndroidTimePicker>(uri, 0, 21, "TimePicker");
    qmlRegisterType<QQmlAndroidToast>(uri, 0, 21, "Toast");
    qmlRegisterType<QQmlAndroidToggleButton>(uri, 0, 21, "ToggleButton");
    qmlRegisterType<QQmlAndroidViewAnimator>(uri, 0, 21, "ViewAnimator");
    qmlRegisterType<QQmlAndroidViewFlipper>(uri, 0, 21, "ViewFlipper");
    qmlRegisterType<QQmlAndroidViewSwitcher>(uri, 0, 21, "ViewSwitcher");
}

QT_END_NAMESPACE

#include "qtqmlandroidwidgetplugin.moc"
