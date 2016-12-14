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

#include "qnativeandroidanticipateovershootinterpolator_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidAnticipateOvershootInterpolator::QNativeAndroidAnticipateOvershootInterpolator(QObject *parent) :
    QNativeAndroidInterpolator(parent)
{
}

qreal QNativeAndroidAnticipateOvershootInterpolator::tension() const
{
    if (m_tension.isNull())
        return 1.0;
    return m_tension;
}

void QNativeAndroidAnticipateOvershootInterpolator::setTension(qreal tension)
{
    if (m_tension.isNull() || m_tension != tension) {
        m_tension = tension;
        emit tensionChanged();
    }
}

qreal QNativeAndroidAnticipateOvershootInterpolator::extraTension() const
{
    if (m_extraTension.isNull())
        return 1.0;
    return m_extraTension;
}

void QNativeAndroidAnticipateOvershootInterpolator::setExtraTension(qreal tension)
{
    if (m_extraTension.isNull() || m_extraTension != tension) {
        m_extraTension = tension;
        emit extraTensionChanged();
    }
}

QAndroidJniObject QNativeAndroidAnticipateOvershootInterpolator::onCreate()
{
    if (m_tension.isNull() && m_extraTension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator");

    if (!m_tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                                 "(F)V",
                                 m_tension);

    return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                             "(FF)V",
                             m_tension,
                             m_extraTension);
}

QT_END_NAMESPACE
