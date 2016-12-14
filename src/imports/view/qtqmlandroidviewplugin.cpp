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

#include <QtQmlAndroid/private/qnativeandroidgravity_p.h>
#include <QtQmlAndroid/private/qnativeandroidlayoutparams_p.h>
#include <QtQmlAndroid/private/qnativeandroidmenu_p.h>
#include <QtQmlAndroid/private/qnativeandroidmenuitem_p.h>
#include <QtQmlAndroid/private/qnativeandroidview_p.h>
#include <QtQmlAndroid/private/qnativeandroidviewgroup_p.h>
#include <QtQmlAndroid/private/qnativeandroidwindow_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidViewPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri) override;
};

void QtQmlAndroidViewPlugin::registerTypes(const char *uri)
{
    qmlRegisterUncreatableType<QNativeAndroidGravity>(uri, 0, 21, "Gravity", QStringLiteral("Gravity is an enum"));
    qmlRegisterUncreatableType<QNativeAndroidLayoutParams>(uri, 0, 21, "Layout", QStringLiteral("Layout is an attached property"));
    qmlRegisterType<QNativeAndroidMenu>(uri, 0, 21, "Menu");
    qmlRegisterType<QNativeAndroidMenuItem>(uri, 0, 21, "MenuItem");
    qmlRegisterType<QNativeAndroidView>(uri, 0, 21, "View");
    qmlRegisterType<QNativeAndroidViewGroup>(uri, 0, 21, "ViewGroup");
    qmlRegisterType<QNativeAndroidWindow>();
}

QT_END_NAMESPACE

#include "qtqmlandroidviewplugin.moc"
