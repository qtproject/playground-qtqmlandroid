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

#include "qqmlandroidtranslateanimation_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidTranslateAnimation::QQmlAndroidTranslateAnimation(QObject *parent) :
    QQmlAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_fromXType(ABSOLUTE), m_fromYType(ABSOLUTE), m_toXType(ABSOLUTE), m_toYType(ABSOLUTE)
{
}

qreal QQmlAndroidTranslateAnimation::fromX() const
{
    return m_fromX;
}

void QQmlAndroidTranslateAnimation::setFromX(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXChanged();
    }
}

qreal QQmlAndroidTranslateAnimation::fromY() const
{
    return m_fromY;
}

void QQmlAndroidTranslateAnimation::setFromY(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYChanged();
    }
}

qreal QQmlAndroidTranslateAnimation::toX() const
{
    return m_toX;
}

void QQmlAndroidTranslateAnimation::setToX(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXChanged();
    }
}

qreal QQmlAndroidTranslateAnimation::toY() const
{
    return m_toY;
}

void QQmlAndroidTranslateAnimation::setToY(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidTranslateAnimation::fromXType() const
{
    return m_fromXType;
}

void QQmlAndroidTranslateAnimation::setFromXType(Relation type)
{
    if (m_fromXType != type) {
        m_fromXType = type;
        emit fromXTypeChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidTranslateAnimation::fromYType() const
{
    return m_fromYType;
}

void QQmlAndroidTranslateAnimation::setFromYType(Relation type)
{
    if (m_fromYType != type) {
        m_fromYType = type;
        emit fromYTypeChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidTranslateAnimation::toXType() const
{
    return m_toXType;
}

void QQmlAndroidTranslateAnimation::setToXType(Relation type)
{
    if (m_toXType != type) {
        m_toXType = type;
        emit toXTypeChanged();
    }
}

QQmlAndroidAnimation::Relation QQmlAndroidTranslateAnimation::toYType() const
{
    return m_toYType;
}

void QQmlAndroidTranslateAnimation::setToYType(Relation type)
{
    if (m_toYType != type) {
        m_toYType = type;
        emit toYTypeChanged();
    }
}

QAndroidJniObject QQmlAndroidTranslateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/TranslateAnimation",
                             "(IFIFIFIF)V",
                             m_fromXType, m_fromX, m_toXType, m_toX,
                             m_fromYType, m_fromY, m_toYType, m_toY);
}

QT_END_NAMESPACE
