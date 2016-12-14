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

#include "qnativeandroidpathinterpolator_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidPathInterpolator::QNativeAndroidPathInterpolator(QObject *parent) :
    QNativeAndroidInterpolator(parent)
{
}

qreal QNativeAndroidPathInterpolator::controlX() const
{
    if (m_controlX.isNull())
        return 0.0;
    return m_controlX;
}

void QNativeAndroidPathInterpolator::setControlX(qreal x)
{
    if (m_controlX.isNull() || m_controlX != x) {
        m_controlX = x;
        emit controlXChanged();
    }
}

qreal QNativeAndroidPathInterpolator::controlY() const
{
    if (m_controlY.isNull())
        return 0.0;
    return m_controlY;
}

void QNativeAndroidPathInterpolator::setControlY(qreal y)
{
    if (m_controlY.isNull() || m_controlY != y) {
        m_controlY = y;
        emit controlYChanged();
    }
}

qreal QNativeAndroidPathInterpolator::controlX2() const
{
    if (m_controlX2.isNull())
        return 0.0;
    return m_controlX2;
}

void QNativeAndroidPathInterpolator::setControlX2(qreal x)
{
    if (m_controlX2.isNull() || m_controlX2 != x) {
        m_controlX2 = x;
        emit controlX2Changed();
    }
}

qreal QNativeAndroidPathInterpolator::controlY2() const
{
    if (m_controlY2.isNull())
        return 0.0;
    return m_controlY2;
}

void QNativeAndroidPathInterpolator::setControlY2(qreal y)
{
    if (m_controlY2.isNull() || m_controlY2 != y) {
        m_controlY2 = y;
        emit controlY2Changed();
    }
}

QAndroidJniObject QNativeAndroidPathInterpolator::onCreate()
{
    if (!m_controlX.isNull() && !m_controlY.isNull() && !m_controlX2.isNull() && !m_controlY2.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FFFF)V",
                                 m_controlX,
                                 m_controlY,
                                 m_controlX2,
                                 m_controlY2);

    if (!m_controlX.isNull() && !m_controlY.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FF)V",
                                 m_controlX,
                                 m_controlY);

    return QAndroidJniObject();
}

QT_END_NAMESPACE
