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

#include "qnativeandroidrotateanimation_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidRotateAnimation::QNativeAndroidRotateAnimation(QObject *parent) :
    QNativeAndroidAnimation(parent), m_from(0), m_to(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QNativeAndroidRotateAnimation::fromDegrees() const
{
    return m_from;
}

void QNativeAndroidRotateAnimation::setFromDegrees(qreal degrees)
{
    if (m_from != degrees) {
        m_from = degrees;
        emit fromDegreesChanged();
    }
}

qreal QNativeAndroidRotateAnimation::toDegrees() const
{
    return m_to;
}

void QNativeAndroidRotateAnimation::setToDegrees(qreal degrees)
{
    if (m_to != degrees) {
        m_to = degrees;
        emit toDegreesChanged();
    }
}

qreal QNativeAndroidRotateAnimation::pivotX() const
{
    return m_pivotX;
}

void QNativeAndroidRotateAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QNativeAndroidRotateAnimation::pivotY() const
{
    return m_pivotY;
}

void QNativeAndroidRotateAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QNativeAndroidRotateAnimation::Relation QNativeAndroidRotateAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QNativeAndroidRotateAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QNativeAndroidRotateAnimation::Relation QNativeAndroidRotateAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QNativeAndroidRotateAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QNativeAndroidRotateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/RotateAnimation",
                             "(FFIFIF)V",
                             m_from, m_to,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
