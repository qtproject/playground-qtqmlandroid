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

#include "qtqmlandroidsupportmodule_p.h"

#include "qqmlandroiddrawerlayout_p.h"
#include "qqmlandroidswiperefreshlayout_p.h"

#include "qqmlandroidactionbardrawertoggle_p.h"

#include "qqmlandroidcardview_p.h"
#include "qqmlandroidrecycleradapter_p.h"
#include "qqmlandroidrecyclerview_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerSupportV4WidgetModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidDrawerLayout>(uri, 0, 21, "DrawerLayout");
    qmlRegisterType<QQmlAndroidSwipeRefreshLayout>(uri, 0, 21, "SwipeRefreshLayout");
}

void registerSupportV7AppModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidActionBarDrawerToggle>(uri, 0, 21, "ActionBarDrawerToggle");
}

void registerSupportV7WidgetModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidCardView>(uri, 0, 21, "CardView");
    qmlRegisterType<QQmlAndroidRecyclerAdapter>(uri, 0, 21, "RecyclerAdapter");
    qmlRegisterType<QQmlAndroidRecyclerView>(uri, 0, 21, "RecyclerView");
}

}

QT_END_NAMESPACE
