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
#include "qnativeandroidcontextwrapper_p_p.h"
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

class QNativeAndroidActivityPrivate : public QNativeAndroidContextWrapperPrivate
{
public:
    QNativeAndroidWindow *window = nullptr;
    QNativeAndroidView *contentView = nullptr;
    QNativeAndroidMenu *optionsMenu = nullptr;
    QNativeAndroidActionBar *actionBar = nullptr;
};

QNativeAndroidActivity::QNativeAndroidActivity(QObject *parent)
    : QNativeAndroidContextWrapper(*(new QNativeAndroidActivityPrivate), parent)
{
    Q_D(QNativeAndroidActivity);
    d->window = new QNativeAndroidWindow(this);

    // TODO: multiple activities?
    setInstance(QtAndroid::androidActivity());
}

QNativeAndroidWindow *QNativeAndroidActivity::window() const
{
    Q_D(const QNativeAndroidActivity);
    return d->window;
}

QNativeAndroidActionBar *QNativeAndroidActivity::actionBar() const
{
    Q_D(const QNativeAndroidActivity);
    return d->actionBar;
}

void QNativeAndroidActivity::setActionBar(QNativeAndroidActionBar *bar)
{
    Q_D(QNativeAndroidActivity);
    if (d->actionBar != bar) {
        if (d->actionBar)
            d->actionBar->destruct();
        d->actionBar = bar;
        if (d->actionBar)
            setupActionBar();
    }
}

QNativeAndroidMenu *QNativeAndroidActivity::optionsMenu() const
{
    Q_D(const QNativeAndroidActivity);
    return d->optionsMenu;
}

void QNativeAndroidActivity::setOptionsMenu(QNativeAndroidMenu *menu)
{
    Q_D(QNativeAndroidActivity);
    if (d->optionsMenu != menu) {
        if (d->optionsMenu) {
            disconnect(d->optionsMenu, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateOptionsMenu);
            d->optionsMenu->destruct();
        }
        d->optionsMenu = menu;
        if (d->optionsMenu) {
            connect(d->optionsMenu, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateOptionsMenu);
            if (isComponentComplete())
                d->optionsMenu->construct();
        }
    }
}

QNativeAndroidView *QNativeAndroidActivity::contentView() const
{
    Q_D(const QNativeAndroidActivity);
    return d->contentView;
}

void QNativeAndroidActivity::setContentView(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidActivity);
    if (d->contentView != view) {
        if (d->contentView) {
            disconnect(d->contentView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateContentView);
            d->contentView->destruct();
        }
        d->contentView = view;
        if (d->contentView) {
            connect(d->contentView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidActivity::updateContentView);
            if (isComponentComplete())
                d->contentView->construct();
        }
    }
}

void QNativeAndroidActivity::start()
{
    Q_D(QNativeAndroidActivity);
    foreach (QObject *child, children()) {
        QNativeAndroidObject *object = qobject_cast<QNativeAndroidObject *>(child);
        if (object)
            object->construct();
    }

    if (d->actionBar)
        setupActionBar();

    if (d->window)
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
    Q_D(QNativeAndroidActivity);
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject wnd = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        d->window->inflate(wnd);
    });
}

void QNativeAndroidActivity::setupActionBar()
{
    Q_D(QNativeAndroidActivity);
    if (!isValid())
        return;

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject bar = activity.callObjectMethod("getActionBar", "()Landroid/app/ActionBar;");
        d->actionBar->inflate(bar);
    });
}

void QNativeAndroidActivity::updateOptionsMenu()
{
    Q_D(QNativeAndroidActivity);
    if (!isValid())
        return;

    QAndroidJniObject menu;
    if (d->optionsMenu)
        menu = d->optionsMenu->instance();

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
    Q_D(QNativeAndroidActivity);
    if (!isValid())
        return;

    QAndroidJniObject content;
    if (d->contentView)
        content = d->contentView->instance();

    QAndroidJniObject activity = instance();
    QtNativeAndroid::callFunction([=]() {
        activity.callMethod<void>("setContentView", "(Landroid/view/View;)V", content.object());
    });
}

QT_END_NAMESPACE
