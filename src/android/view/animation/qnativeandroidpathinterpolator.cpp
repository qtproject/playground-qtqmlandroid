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
#include "qnativeandroidinterpolator_p_p.h"
#include "qnativeandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidPathInterpolatorPrivate : public QNativeAndroidInterpolatorPrivate
{
public:
    QNativeAndroidOptional<qreal> controlX;
    QNativeAndroidOptional<qreal> controlY;
    QNativeAndroidOptional<qreal> controlX2;
    QNativeAndroidOptional<qreal> controlY2;
};

QNativeAndroidPathInterpolator::QNativeAndroidPathInterpolator(QObject *parent)
    : QNativeAndroidInterpolator(*(new QNativeAndroidPathInterpolatorPrivate), parent)
{
}

qreal QNativeAndroidPathInterpolator::controlX() const
{
    Q_D(const QNativeAndroidPathInterpolator);
    if (d->controlX.isNull())
        return 0.0;
    return d->controlX;
}

void QNativeAndroidPathInterpolator::setControlX(qreal x)
{
    Q_D(QNativeAndroidPathInterpolator);
    if (d->controlX.isNull() || d->controlX != x) {
        d->controlX = x;
        emit controlXChanged();
    }
}

qreal QNativeAndroidPathInterpolator::controlY() const
{
    Q_D(const QNativeAndroidPathInterpolator);
    if (d->controlY.isNull())
        return 0.0;
    return d->controlY;
}

void QNativeAndroidPathInterpolator::setControlY(qreal y)
{
    Q_D(QNativeAndroidPathInterpolator);
    if (d->controlY.isNull() || d->controlY != y) {
        d->controlY = y;
        emit controlYChanged();
    }
}

qreal QNativeAndroidPathInterpolator::controlX2() const
{
    Q_D(const QNativeAndroidPathInterpolator);
    if (d->controlX2.isNull())
        return 0.0;
    return d->controlX2;
}

void QNativeAndroidPathInterpolator::setControlX2(qreal x)
{
    Q_D(QNativeAndroidPathInterpolator);
    if (d->controlX2.isNull() || d->controlX2 != x) {
        d->controlX2 = x;
        emit controlX2Changed();
    }
}

qreal QNativeAndroidPathInterpolator::controlY2() const
{
    Q_D(const QNativeAndroidPathInterpolator);
    if (d->controlY2.isNull())
        return 0.0;
    return d->controlY2;
}

void QNativeAndroidPathInterpolator::setControlY2(qreal y)
{
    Q_D(QNativeAndroidPathInterpolator);
    if (d->controlY2.isNull() || d->controlY2 != y) {
        d->controlY2 = y;
        emit controlY2Changed();
    }
}

QAndroidJniObject QNativeAndroidPathInterpolator::onCreate()
{
    Q_D(QNativeAndroidPathInterpolator);
    if (!d->controlX.isNull() && !d->controlY.isNull() && !d->controlX2.isNull() && !d->controlY2.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FFFF)V",
                                 d->controlX,
                                 d->controlY,
                                 d->controlX2,
                                 d->controlY2);

    if (!d->controlX.isNull() && !d->controlY.isNull())
        return QAndroidJniObject("android/view/animation/PathInterpolator",
                                 "(FF)V",
                                 d->controlX,
                                 d->controlY);

    return QAndroidJniObject();
}

QT_END_NAMESPACE
