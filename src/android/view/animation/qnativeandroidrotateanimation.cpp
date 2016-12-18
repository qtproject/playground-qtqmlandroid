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
#include "qnativeandroidanimation_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidRotateAnimationPrivate : public QNativeAndroidAnimationPrivate
{
public:
    qreal from = 0.0;
    qreal to = 0.0;
    qreal pivotX = 0.0;
    qreal pivotY = 0.0;
    QNativeAndroidRotateAnimation::Relation pivotXType = QNativeAndroidRotateAnimation::ABSOLUTE;
    QNativeAndroidRotateAnimation::Relation pivotYType = QNativeAndroidRotateAnimation::ABSOLUTE;
};

QNativeAndroidRotateAnimation::QNativeAndroidRotateAnimation(QObject *parent)
    : QNativeAndroidAnimation(*(new QNativeAndroidRotateAnimationPrivate), parent)
{
}

qreal QNativeAndroidRotateAnimation::fromDegrees() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->from;
}

void QNativeAndroidRotateAnimation::setFromDegrees(qreal degrees)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->from != degrees) {
        d->from = degrees;
        emit fromDegreesChanged();
    }
}

qreal QNativeAndroidRotateAnimation::toDegrees() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->to;
}

void QNativeAndroidRotateAnimation::setToDegrees(qreal degrees)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->to != degrees) {
        d->to = degrees;
        emit toDegreesChanged();
    }
}

qreal QNativeAndroidRotateAnimation::pivotX() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->pivotX;
}

void QNativeAndroidRotateAnimation::setPivotX(qreal pivotX)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->pivotX != pivotX) {
        d->pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QNativeAndroidRotateAnimation::pivotY() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->pivotY;
}

void QNativeAndroidRotateAnimation::setPivotY(qreal pivotY)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->pivotY != pivotY) {
        d->pivotY = pivotY;
        emit pivotYChanged();
    }
}

QNativeAndroidRotateAnimation::Relation QNativeAndroidRotateAnimation::pivotXType() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->pivotXType;
}

void QNativeAndroidRotateAnimation::setPivotXType(Relation type)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->pivotXType != type) {
        d->pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QNativeAndroidRotateAnimation::Relation QNativeAndroidRotateAnimation::pivotYType() const
{
    Q_D(const QNativeAndroidRotateAnimation);
    return d->pivotYType;
}

void QNativeAndroidRotateAnimation::setPivotYType(Relation type)
{
    Q_D(QNativeAndroidRotateAnimation);
    if (d->pivotYType != type) {
        d->pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QNativeAndroidRotateAnimation::onCreate()
{
    Q_D(QNativeAndroidRotateAnimation);
    return QAndroidJniObject("android/view/animation/RotateAnimation",
                             "(FFIFIF)V",
                             d->from, d->to,
                             d->pivotXType, d->pivotX, d->pivotYType, d->pivotY);
}

QT_END_NAMESPACE
