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
#include "qnativeandroidinterpolator_p_p.h"
#include "qnativeandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidAnticipateOvershootInterpolatorPrivate : public QNativeAndroidInterpolatorPrivate
{
public:
    QNativeAndroidOptional<qreal> tension;
    QNativeAndroidOptional<qreal> extraTension;
};

QNativeAndroidAnticipateOvershootInterpolator::QNativeAndroidAnticipateOvershootInterpolator(QObject *parent)
    : QNativeAndroidInterpolator(*(new QNativeAndroidAnticipateOvershootInterpolatorPrivate), parent)
{
}

qreal QNativeAndroidAnticipateOvershootInterpolator::tension() const
{
    Q_D(const QNativeAndroidAnticipateOvershootInterpolator);
    if (d->tension.isNull())
        return 1.0;
    return d->tension;
}

void QNativeAndroidAnticipateOvershootInterpolator::setTension(qreal tension)
{
    Q_D(QNativeAndroidAnticipateOvershootInterpolator);
    if (d->tension.isNull() || d->tension != tension) {
        d->tension = tension;
        emit tensionChanged();
    }
}

qreal QNativeAndroidAnticipateOvershootInterpolator::extraTension() const
{
    Q_D(const QNativeAndroidAnticipateOvershootInterpolator);
    if (d->extraTension.isNull())
        return 1.0;
    return d->extraTension;
}

void QNativeAndroidAnticipateOvershootInterpolator::setExtraTension(qreal tension)
{
    Q_D(QNativeAndroidAnticipateOvershootInterpolator);
    if (d->extraTension.isNull() || d->extraTension != tension) {
        d->extraTension = tension;
        emit extraTensionChanged();
    }
}

QAndroidJniObject QNativeAndroidAnticipateOvershootInterpolator::onCreate()
{
    Q_D(QNativeAndroidAnticipateOvershootInterpolator);
    if (d->tension.isNull() && d->extraTension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator");

    if (!d->tension.isNull())
        return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                                 "(F)V",
                                 d->tension);

    return QAndroidJniObject("android/view/animation/AnticipateOvershootInterpolator",
                             "(FF)V",
                             d->tension,
                             d->extraTension);
}

QT_END_NAMESPACE
