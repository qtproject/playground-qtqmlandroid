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

#include "qnativeandroidtranslateanimation_p.h"
#include "qnativeandroidanimation_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidTranslateAnimationPrivate : public QNativeAndroidAnimationPrivate
{
public:
    qreal fromX = 0.0;
    qreal fromY = 0.0;
    qreal toX = 0.0;
    qreal toY = 0.0;
    QNativeAndroidTranslateAnimation::Relation fromXType = QNativeAndroidTranslateAnimation::ABSOLUTE;
    QNativeAndroidTranslateAnimation::Relation fromYType = QNativeAndroidTranslateAnimation::ABSOLUTE;
    QNativeAndroidTranslateAnimation::Relation toXType = QNativeAndroidTranslateAnimation::ABSOLUTE;
    QNativeAndroidTranslateAnimation::Relation toYType = QNativeAndroidTranslateAnimation::ABSOLUTE;
};

QNativeAndroidTranslateAnimation::QNativeAndroidTranslateAnimation(QObject *parent)
    : QNativeAndroidAnimation(*(new QNativeAndroidTranslateAnimationPrivate), parent)
{
}

qreal QNativeAndroidTranslateAnimation::fromX() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->fromX;
}

void QNativeAndroidTranslateAnimation::setFromX(qreal x)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->fromX != x) {
        d->fromX = x;
        emit fromXChanged();
    }
}

qreal QNativeAndroidTranslateAnimation::fromY() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->fromY;
}

void QNativeAndroidTranslateAnimation::setFromY(qreal y)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->fromY != y) {
        d->fromY = y;
        emit fromYChanged();
    }
}

qreal QNativeAndroidTranslateAnimation::toX() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->toX;
}

void QNativeAndroidTranslateAnimation::setToX(qreal x)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->toX != x) {
        d->toX = x;
        emit toXChanged();
    }
}

qreal QNativeAndroidTranslateAnimation::toY() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->toY;
}

void QNativeAndroidTranslateAnimation::setToY(qreal y)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->toY != y) {
        d->toY = y;
        emit toYChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidTranslateAnimation::fromXType() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->fromXType;
}

void QNativeAndroidTranslateAnimation::setFromXType(Relation type)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->fromXType != type) {
        d->fromXType = type;
        emit fromXTypeChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidTranslateAnimation::fromYType() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->fromYType;
}

void QNativeAndroidTranslateAnimation::setFromYType(Relation type)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->fromYType != type) {
        d->fromYType = type;
        emit fromYTypeChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidTranslateAnimation::toXType() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->toXType;
}

void QNativeAndroidTranslateAnimation::setToXType(Relation type)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->toXType != type) {
        d->toXType = type;
        emit toXTypeChanged();
    }
}

QNativeAndroidAnimation::Relation QNativeAndroidTranslateAnimation::toYType() const
{
    Q_D(const QNativeAndroidTranslateAnimation);
    return d->toYType;
}

void QNativeAndroidTranslateAnimation::setToYType(Relation type)
{
    Q_D(QNativeAndroidTranslateAnimation);
    if (d->toYType != type) {
        d->toYType = type;
        emit toYTypeChanged();
    }
}

QAndroidJniObject QNativeAndroidTranslateAnimation::onCreate()
{
    Q_D(QNativeAndroidTranslateAnimation);
    return QAndroidJniObject("android/view/animation/TranslateAnimation",
                             "(IFIFIFIF)V",
                             d->fromXType, d->fromX, d->toXType, d->toX,
                             d->fromYType, d->fromY, d->toYType, d->toY);
}

QT_END_NAMESPACE
