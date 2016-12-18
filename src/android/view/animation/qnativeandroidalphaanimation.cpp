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

#include "qnativeandroidalphaanimation_p.h"
#include "qnativeandroidanimation_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidAlphaAnimationPrivate : public QNativeAndroidAnimationPrivate
{
public:
    qreal fromAlpha = 0.0;
    qreal toAlpha = 0.0;
};

QNativeAndroidAlphaAnimation::QNativeAndroidAlphaAnimation(QObject *parent)
    : QNativeAndroidAnimation(*(new QNativeAndroidAlphaAnimationPrivate), parent)
{
}

qreal QNativeAndroidAlphaAnimation::fromAlpha() const
{
    Q_D(const QNativeAndroidAlphaAnimation);
    return d->fromAlpha;
}

void QNativeAndroidAlphaAnimation::setFromAlpha(qreal alpha)
{
    Q_D(QNativeAndroidAlphaAnimation);
    if (d->fromAlpha != alpha) {
        d->fromAlpha = alpha;
        emit fromAlphaChanged();
    }
}

qreal QNativeAndroidAlphaAnimation::toAlpha() const
{
    Q_D(const QNativeAndroidAlphaAnimation);
    return d->toAlpha;
}

void QNativeAndroidAlphaAnimation::setToAlpha(qreal alpha)
{
    Q_D(QNativeAndroidAlphaAnimation);
    if (d->toAlpha != alpha) {
        d->toAlpha = alpha;
        emit toAlphaChanged();
    }
}

QAndroidJniObject QNativeAndroidAlphaAnimation::onCreate()
{
    Q_D(QNativeAndroidAlphaAnimation);
    return QAndroidJniObject("android/view/animation/AlphaAnimation",
                             "(FF)V",
                             d->fromAlpha, d->toAlpha);
}

QT_END_NAMESPACE
