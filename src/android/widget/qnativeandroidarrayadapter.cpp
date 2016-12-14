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

#include "qnativeandroidarrayadapter_p.h"
#include "qnativeandroidadapterview_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidArrayAdapter::QNativeAndroidArrayAdapter(QObject *parent) :
    QNativeAndroidBaseAdapter(parent), m_style(17367043) // TODO: android.R.layout.simple_list_item_1
{
}

int QNativeAndroidArrayAdapter::style() const
{
    return m_style;
}

void QNativeAndroidArrayAdapter::setStyle(int style)
{
    if (m_style != style) {
        m_style = style;
        emit styleChanged();
    }
}

QStringList QNativeAndroidArrayAdapter::array() const
{
    return m_array;
}

void QNativeAndroidArrayAdapter::setArray(const QStringList &array)
{
    if (m_array != array) {
        m_array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QNativeAndroidArrayAdapter::count() const
{
    return m_array.count();
}

QString QNativeAndroidArrayAdapter::getItem(int position) const
{
    return m_array.value(position);
}

void QNativeAndroidArrayAdapter::clear()
{
    if (!m_array.isEmpty()) {
        m_array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QNativeAndroidArrayAdapter::onCreate()
{
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             ctx().object(),
                             m_style);
}

void QNativeAndroidArrayAdapter::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidBaseAdapter::onInflate(instance);

    foreach (const QString &str, m_array)
        instance.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
}

QT_END_NAMESPACE
