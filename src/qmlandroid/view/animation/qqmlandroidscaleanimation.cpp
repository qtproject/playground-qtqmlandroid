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

#include "qqmlandroidscaleanimation_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidScaleAnimation::QQmlAndroidScaleAnimation(QObject *parent) :
    QQmlAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QQmlAndroidScaleAnimation::fromXScale() const
{
    return m_fromX;
}

void QQmlAndroidScaleAnimation::setFromXScale(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::fromYScale() const
{
    return m_fromY;
}

void QQmlAndroidScaleAnimation::setFromYScale(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::toXScale() const
{
    return m_toX;
}

void QQmlAndroidScaleAnimation::setToXScale(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::toYScale() const
{
    return m_toY;
}

void QQmlAndroidScaleAnimation::setToYScale(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYScaleChanged();
    }
}

qreal QQmlAndroidScaleAnimation::pivotX() const
{
    return m_pivotX;
}

void QQmlAndroidScaleAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QQmlAndroidScaleAnimation::pivotY() const
{
    return m_pivotY;
}

void QQmlAndroidScaleAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidScaleAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QQmlAndroidScaleAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidScaleAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QQmlAndroidScaleAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QQmlAndroidScaleAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/ScaleAnimation",
                             "(FFFFIFIF)V",
                             m_fromX, m_toX, m_fromY, m_toY,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
