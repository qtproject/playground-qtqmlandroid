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

#include "qnativeandroidlayoutparams_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidLayoutParams::QNativeAndroidLayoutParams(QNativeAndroidView *view) :
    QNativeAndroidObject(view), m_dirty(false), m_view(view)
{
    m_view->setLayoutParams(this);
}

QNativeAndroidLayoutParams *QNativeAndroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView*>(object);
    if (view)
        return new QNativeAndroidLayoutParams(view);
    return 0;
}

int QNativeAndroidLayoutParams::width() const
{
    if (m_width.isNull())
        return MATCH_PARENT;
    return m_width;
}

void QNativeAndroidLayoutParams::setWidth(int value)
{
    if (value != width()) {
        m_width = value;
        invalidate();
        emit widthChanged();
    }
}

int QNativeAndroidLayoutParams::height() const
{
    if (m_height.isNull())
        return MATCH_PARENT;
    return m_height;
}

void QNativeAndroidLayoutParams::setHeight(int value)
{
    if (value != height()) {
        m_height = value;
        invalidate();
        emit heightChanged();
    }
}

void QNativeAndroidLayoutParams::invalidate()
{
    if (!m_dirty && isValid()) {
        m_dirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
    }
}

QAndroidJniObject QNativeAndroidLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QNativeAndroidLayoutParams::onInflate(QAndroidJniObject &instance)
{
    if (!m_width.isNull())
        instance.setField<int>("width", m_width);
    if (!m_height.isNull())
        instance.setField<int>("height", m_height);
}

bool QNativeAndroidLayoutParams::event(QEvent *event)
{
    if (event->type() == QEvent::LayoutRequest) {
        if (m_dirty && isValid()) {
            construct();
            m_dirty = false;
        }
    }
    return QNativeAndroidObject::event(event);
}

QT_END_NAMESPACE
