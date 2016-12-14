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

#include "qnativeandroidwindow_p.h"
#include "qnativeandroidcontext_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidWindow::QNativeAndroidWindow(QNativeAndroidContext *context) :
    QNativeAndroidContextual(context)
{
    setContext(context);
}

int QNativeAndroidWindow::statusBarColor() const
{
    if (m_statusBarColor.isNull())
        return 0; // TODO
    return m_statusBarColor;
}

void QNativeAndroidWindow::setStatusBarColor(int color)
{
    if (m_statusBarColor.isNull() || m_statusBarColor != color) {
        m_statusBarColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setStatusBarColor", color);
        emit statusBarColorChanged();
    }
}

void QNativeAndroidWindow::onInflate(QAndroidJniObject &instance)
{
    if (!m_statusBarColor.isNull()) {
        // TODO: WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS
        instance.callMethod<void>("addFlags", "(I)V", 0x80000000);
        // TODO: WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS
        instance.callMethod<void>("clearFlags", "(I)V", 0x04000000);
        instance.callMethod<void>("setStatusBarColor", "(I)V", m_statusBarColor);
    }
}

QT_END_NAMESPACE
