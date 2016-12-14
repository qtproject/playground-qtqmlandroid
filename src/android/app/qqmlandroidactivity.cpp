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

#include "qqmlandroidactivity_p.h"
#include "qqmlandroidactionbar_p.h"
#include "qqmlandroidmenuitem_p.h"
#include "qqmlandroidmenu_p.h"
#include "qqmlandroidview_p.h"
#include "qqmlandroidwindow_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

QQmlAndroidActivity::QQmlAndroidActivity(QObject *parent) :
    QQmlAndroidContextWrapper(parent), m_window(new QQmlAndroidWindow(this)),
    m_contentView(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QQmlAndroidWindow *QQmlAndroidActivity::window() const
{
    return m_window;
}

QQmlAndroidActionBar *QQmlAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QQmlAndroidActivity::setActionBar(QQmlAndroidActionBar *bar)
{
    if (m_actionBar != bar) {
        if (m_actionBar)
            m_actionBar->destruct();
        m_actionBar = bar;
        if (m_actionBar)
            setupActionBar();
    }
}

QQmlAndroidMenu *QQmlAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QQmlAndroidActivity::setOptionsMenu(QQmlAndroidMenu *menu)
{
    if (m_optionsMenu != menu) {
        if (m_optionsMenu) {
            disconnect(m_optionsMenu, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateOptionsMenu);
            m_optionsMenu->destruct();
        }
        m_optionsMenu = menu;
        if (m_optionsMenu) {
            connect(m_optionsMenu, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateOptionsMenu);
            if (isComponentComplete())
                m_optionsMenu->construct();
        }
    }
}

QQmlAndroidView *QQmlAndroidActivity::contentView() const
{
    return m_contentView;
}

void QQmlAndroidActivity::setContentView(QQmlAndroidView *view)
{
    if (m_contentView != view) {
        if (m_contentView) {
            disconnect(m_contentView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateContentView);
            m_contentView->destruct();
        }
        m_contentView = view;
        if (m_contentView) {
            connect(m_contentView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidActivity::updateContentView);
            if (isComponentComplete())
                m_contentView->construct();
        }
    }
}

void QQmlAndroidActivity::classBegin()
{
    QQmlAndroidContextWrapper::classBegin();
}

void QQmlAndroidActivity::componentComplete()
{
    QQmlAndroidContextWrapper::componentComplete();

    foreach (QObject *child, children()) {
        QQmlAndroidObject *object = qobject_cast<QQmlAndroidObject *>(child);
        if (object)
            object->construct();
    }

    if (m_actionBar)
        setupActionBar();

    if (m_window)
        setupWindow();
}

void QQmlAndroidActivity::setupWindow()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        m_window->inflate(wnd);
    });
}

void QQmlAndroidActivity::setupActionBar()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        m_actionBar->inflate(bar);
    });
}

void QQmlAndroidActivity::updateOptionsMenu()
{
    if (!isValid())
        return;

    QAndroidJniObject menu;
    if (m_optionsMenu)
        menu = m_optionsMenu->instance();

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        activity.callMethod<void>("setOptionsMenu", "(Lqt/android/view/QmlMenu;)V", menu.object());
    });
}

void QQmlAndroidActivity::invalidateOptionsMenu()
{
    QtQmlAndroid::callVoidMethod(instance(), "invalidateOptionsMenu");
}

void QQmlAndroidActivity::updateContentView()
{
    if (!isValid())
        return;

    QAndroidJniObject content;
    if (m_contentView)
        content = m_contentView->instance();

    QAndroidJniObject activity = instance();
    QtQmlAndroid::callFunction([=]() {
        activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
    });
}

QT_END_NAMESPACE
