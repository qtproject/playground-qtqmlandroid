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

#include "qnativeandroidpopupmenu_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qnativeandroidmenuitem_p.h"
#include "qnativeandroidcontext_p.h"
#include "qnativeandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QNativeAndroidPopupMenu::QNativeAndroidPopupMenu(QObject *parent) :
    QNativeAndroidObject(parent), m_anchor(0)
{
}

QList<QNativeAndroidMenuItem *> QNativeAndroidPopupMenu::items() const
{
    QList<QNativeAndroidMenuItem *> lst;
    foreach (QObject *child, children()) {
        QNativeAndroidMenuItem *item = qobject_cast<QNativeAndroidMenuItem *>(child);
        if (item)
            lst += item;
    }
    return lst;
}

QNativeAndroidView *QNativeAndroidPopupMenu::anchor() const
{
    return m_anchor;
}

void QNativeAndroidPopupMenu::setAnchor(QNativeAndroidView *anchor)
{
    if (m_anchor != anchor) {
        m_anchor = anchor;
        emit anchorChanged();
    }
}

int QNativeAndroidPopupMenu::gravity() const
{
    if (m_gravity.isNull())
        return 0; // TODO
    return m_gravity;
}

void QNativeAndroidPopupMenu::setGravity(int value)
{
    if (value != gravity()) {
        m_gravity = value;
        emit gravityChanged();
    }
}

void QNativeAndroidPopupMenu::show()
{
    QNativeAndroidView *anchor = m_anchor ? m_anchor : qobject_cast<QNativeAndroidView *>(parent());
    if (!anchor) {
        qWarning() << "PopupMenu parent must be either anchored or in a view.";
        return;
    }

    QNativeAndroidContext *context = anchor->context();
    if (!context) {
        qWarning() << "PopupMenu is not ready - no context.";
        return;
    }

    QAndroidJniObject c = context->instance();
    QAndroidJniObject a = anchor->instance();

    QtQmlAndroid::callFunction([=]() {
        QAndroidJniObject popup;
        if (!m_gravity.isNull()) {
            popup = QAndroidJniObject("android/widget/PopupMenu",
                                      "(Landroid/content/Context;Landroid/view/View;I)V",
                                      c.object(), a.object(), m_gravity);
        } else {
            popup = QAndroidJniObject("android/widget/PopupMenu",
                                      "(Landroid/content/Context;Landroid/view/View;)V",
                                      c.object(), a.object());
        }
        inflate(popup);

        QAndroidJniObject menu = popup.callObjectMethod("getMenu", "()Landroid/view/Menu;");
        foreach (QNativeAndroidMenuItem *item, items()) {
            QAndroidJniObject it = menu.callObjectMethod("add",
                                                         "(Ljava/lang/CharSequence;)Landroid/view/MenuItem;",
                                                         QAndroidJniObject::fromString(item->title()).object());
            //it.callMethod<void>("...");
        }

        popup.callMethod<void>("show");
    });
}

void QNativeAndroidPopupMenu::dismiss()
{
    QtQmlAndroid::callVoidMethod(instance(), "dismiss");
}

QT_END_NAMESPACE
