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

#include "qnativeandroidscaleanimation_p.h"
#include "qnativeandroidanimation_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidScaleAnimationPrivate : public QNativeAndroidAnimationPrivate
{
public:
    qreal fromX = 0.0;
    qreal fromY = 0.0;
    qreal toX = 0.0;
    qreal toY = 0.0;
    qreal pivotX = 0.0;
    qreal pivotY = 0.0;
    QNativeAndroidScaleAnimation::Relation pivotXType = QNativeAndroidScaleAnimation::ABSOLUTE;
    QNativeAndroidScaleAnimation::Relation pivotYType = QNativeAndroidScaleAnimation::ABSOLUTE;
};

QNativeAndroidScaleAnimation::QNativeAndroidScaleAnimation(QObject *parent)
    : QNativeAndroidAnimation(*(new QNativeAndroidScaleAnimationPrivate), parent)
{
}

qreal QNativeAndroidScaleAnimation::fromXScale() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->fromX;
}

void QNativeAndroidScaleAnimation::setFromXScale(qreal x)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->fromX != x) {
        d->fromX = x;
        emit fromXScaleChanged();
    }
}

qreal QNativeAndroidScaleAnimation::fromYScale() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->fromY;
}

void QNativeAndroidScaleAnimation::setFromYScale(qreal y)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->fromY != y) {
        d->fromY = y;
        emit fromYScaleChanged();
    }
}

qreal QNativeAndroidScaleAnimation::toXScale() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->toX;
}

void QNativeAndroidScaleAnimation::setToXScale(qreal x)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->toX != x) {
        d->toX = x;
        emit toXScaleChanged();
    }
}

qreal QNativeAndroidScaleAnimation::toYScale() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->toY;
}

void QNativeAndroidScaleAnimation::setToYScale(qreal y)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->toY != y) {
        d->toY = y;
        emit toYScaleChanged();
    }
}

qreal QNativeAndroidScaleAnimation::pivotX() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->pivotX;
}

void QNativeAndroidScaleAnimation::setPivotX(qreal pivotX)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->pivotX != pivotX) {
        d->pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QNativeAndroidScaleAnimation::pivotY() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->pivotY;
}

void QNativeAndroidScaleAnimation::setPivotY(qreal pivotY)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->pivotY != pivotY) {
        d->pivotY = pivotY;
        emit pivotYChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidScaleAnimation::pivotXType() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->pivotXType;
}

void QNativeAndroidScaleAnimation::setPivotXType(Relation type)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->pivotXType != type) {
        d->pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidScaleAnimation::pivotYType() const
{
    Q_D(const QNativeAndroidScaleAnimation);
    return d->pivotYType;
}

void QNativeAndroidScaleAnimation::setPivotYType(Relation type)
{
    Q_D(QNativeAndroidScaleAnimation);
    if (d->pivotYType != type) {
        d->pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QNativeAndroidScaleAnimation::onCreate()
{
    Q_D(QNativeAndroidScaleAnimation);
    return QAndroidJniObject("android/view/animation/ScaleAnimation",
                             "(FFFFIFIF)V",
                             d->fromX, d->toX, d->fromY, d->toY,
                             d->pivotXType, d->pivotX, d->pivotYType, d->pivotY);
}

QT_END_NAMESPACE
