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

#include "qnativeandroidactivity_p.h"
#include "qnativeandroidactionbar_p.h"
#include "qnativeandroidmenuitem_p.h"
#include "qnativeandroidmenu_p.h"
#include "qnativeandroidview_p.h"
#include "qnativeandroidwindow_p.h"
#include "qtnativeandroidfunctions_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

QNativeAndroidActivity::QNativeAndroidActivity(QObject *parent) :
    QNativeAndroidContextWrapper(parent), m_window(new QNativeAndroidWindow(this)),
    m_contentView(0), m_optionsMenu(0), m_actionBar(0)
{
    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QNativeAndroidWindow *QNativeAndroidActivity::window() const
{
    return m_window;
}

QNativeAndroidActionBar *QNativeAndroidActivity::actionBar() const
{
    return m_actionBar;
}

void QNativeAndroidActivity::setActionBar(QNativeAndroidActionBar *bar)
{
    if (m_actionBar != bar) {
        if (m_actionBar)
            m_actionBar->destruct();
        m_actionBar = bar;
        if (m_actionBar)
            setupActionBar();
    }
}

QNativeAndroidMenu *QNativeAndroidActivity::optionsMenu() const
{
    return m_optionsMenu;
}

void QNativeAndroidActivity::setOptionsMenu(QNativeAndroidMenu *menu)
{
    if (m_optionsMenu != menu) {
        if (m_optionsMenu) {
            disconnect(m_optionsMenu, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateOptionsMenu);
            m_optionsMenu->destruct();
        }
        m_optionsMenu = menu;
        if (m_optionsMenu) {
            connect(m_optionsMenu, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateOptionsMenu);
            if (isComponentComplete())
                m_optionsMenu->construct();
        }
    }
}

QNativeAndroidView *QNativeAndroidActivity::contentView() const
{
    return m_contentView;
}

void QNativeAndroidActivity::setContentView(QNativeAndroidView *view)
{
    if (m_contentView != view) {
        if (m_contentView) {
            disconnect(m_contentView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateContentView);
            m_contentView->destruct();
        }
        m_contentView = view;
        if (m_contentView) {
            connect(m_contentView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateContentView);
            if (isComponentComplete())
                m_contentView->construct();
        }
    }
}

void QNativeAndroidActivity::start()
{
    foreach (QObject *child, children()) {
        QNativeAndroidObject *object = qobject_cast<QNativeAndroidObject *>(child);
        if (object)
            object->construct();
    }

    if (m_actionBar)
        setupActionBar();

    if (m_window)
        setupWindow();
}

void QNativeAndroidActivity::classBegin()
{
    QNativeAndroidContextWrapper::classBegin();
}

void QNativeAndroidActivity::componentComplete()
{
    QNativeAndroidContextWrapper::componentComplete();
    start();
}

void QNativeAndroidActivity::setupWindow()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        m_window->inflate(wnd);
    });
}

void QNativeAndroidActivity::setupActionBar()
{
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        m_actionBar->inflate(bar);
    });
}

void QNativeAndroidActivity::updateOptionsMenu()
{
    if (!isValid())
        return;

    QAndroidJniObject menu;
    if (m_optionsMenu)
        menu = m_optionsMenu->instance();

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        activity.callMethod<void>("setOptionsMenu", "(Lorg/qtproject/qt5/android/bindings/view/QtNativeMenu;)V", menu.object());
    });
}

void QNativeAndroidActivity::invalidateOptionsMenu()
{
    QtNativeAndroid::callVoidMethod(instance(), "invalidateOptionsMenu");
}

void QNativeAndroidActivity::updateContentView()
{
    if (!isValid())
        return;

    QAndroidJniObject content;
    if (m_contentView)
        content = m_contentView->instance();

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
    });
}

QT_END_NAMESPACE
