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

#include <QtQmlAndroid/private/qqmlandroidgravity_p.h>
#include <QtQmlAndroid/private/qqmlandroidlayoutparams_p.h>
#include <QtQmlAndroid/private/qqmlandroidmenu_p.h>
#include <QtQmlAndroid/private/qqmlandroidmenuitem_p.h>
#include <QtQmlAndroid/private/qqmlandroidview_p.h>
#include <QtQmlAndroid/private/qqmlandroidviewgroup_p.h>
#include <QtQmlAndroid/private/qqmlandroidwindow_p.h>

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
    qmlRegisterUncreatableType<QQmlAndroidGravity>(uri, 0, 21, "Gravity", QStringLiteral("Gravity is an enum"));
    qmlRegisterUncreatableType<QQmlAndroidLayoutParams>(uri, 0, 21, "Layout", QStringLiteral("Layout is an attached property"));
    qmlRegisterType<QQmlAndroidMenu>(uri, 0, 21, "Menu");
    qmlRegisterType<QQmlAndroidMenuItem>(uri, 0, 21, "MenuItem");
    qmlRegisterType<QQmlAndroidView>(uri, 0, 21, "View");
    qmlRegisterType<QQmlAndroidViewGroup>(uri, 0, 21, "ViewGroup");
    qmlRegisterType<QQmlAndroidWindow>();
}

QT_END_NAMESPACE

#include "qtqmlandroidviewplugin.moc"
