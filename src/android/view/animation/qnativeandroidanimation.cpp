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

#include "qnativeandroidanimation_p.h"
#include "qnativeandroidanimation_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidAnimation::QNativeAndroidAnimation(QObject *parent)
    : QNativeAndroidContextual(*(new QNativeAndroidAnimationPrivate), parent)
{
}

QNativeAndroidAnimation::QNativeAndroidAnimation(QNativeAndroidAnimationPrivate &dd, QObject *parent)
    : QNativeAndroidContextual(dd, parent)
{
}

int QNativeAndroidAnimation::resource() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->resource.isNull())
        return 0;
    return d->resource;
}

void QNativeAndroidAnimation::setResource(int resource)
{
    Q_D(QNativeAndroidAnimation);
    if (d->resource.isNull() || d->resource != resource) {
        d->resource = resource;
        emit resourceChanged();
    }
}

int QNativeAndroidAnimation::duration() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->duration.isNull())
        return 0;
    return d->duration;
}

void QNativeAndroidAnimation::setDuration(int duration)
{
    Q_D(QNativeAndroidAnimation);
    if (d->duration.isNull() || d->duration != duration) {
        d->duration = duration;
        QtNativeAndroid::callIntMethod(instance(), "setDuration", duration);
        emit durationChanged();
    }
}

bool QNativeAndroidAnimation::fillAfter() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->fillAfter.isNull())
        return false;
    return d->fillAfter;
}

void QNativeAndroidAnimation::setFillAfter(bool fill)
{
    Q_D(QNativeAndroidAnimation);
    if (d->fillAfter.isNull() || d->fillAfter != fill) {
        d->fillAfter = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillAfter", fill);
        emit fillAfterChanged();
    }
}

bool QNativeAndroidAnimation::fillBefore() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->fillBefore.isNull())
        return true;
    return d->fillBefore;
}

void QNativeAndroidAnimation::setFillBefore(bool fill)
{
    Q_D(QNativeAndroidAnimation);
    if (d->fillBefore.isNull() || d->fillBefore != fill) {
        d->fillBefore = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillBefore", fill);
        emit fillBeforeChanged();
    }
}

bool QNativeAndroidAnimation::fillEnabled() const
{
    Q_D(const QNativeAndroidAnimation);
    if (!d->fillEnabled.isNull())
        return false;
    return d->fillEnabled;
}

void QNativeAndroidAnimation::setFillEnabled(bool fill)
{
    Q_D(QNativeAndroidAnimation);
    if (d->fillEnabled.isNull() || d->fillEnabled != fill) {
        d->fillEnabled = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillEnabled", fill);
        emit fillEnabledChanged();
    }
}

QNativeAndroidInterpolator *QNativeAndroidAnimation::interpolator() const
{
    Q_D(const QNativeAndroidAnimation);
    return d->interpolator;
}

void QNativeAndroidAnimation::setInterpolator(QNativeAndroidInterpolator *interpolator)
{
    Q_D(QNativeAndroidAnimation);
    if (d->interpolator != interpolator) {
        if (d->interpolator) {
            disconnect(d->interpolator, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAnimation::updateInterpolator);
            d->interpolator->destruct();
        }
        d->interpolator = interpolator;
        if (d->interpolator) {
            connect(d->interpolator, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAnimation::updateInterpolator);
            if (isValid())
                d->interpolator->construct();
        }
    }
}

int QNativeAndroidAnimation::repeatCount() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->repeatCount.isNull())
        return 0;
    return d->repeatCount;
}

void QNativeAndroidAnimation::setRepeatCount(int count)
{
    Q_D(QNativeAndroidAnimation);
    if (d->repeatCount.isNull() || d->repeatCount != count) {
        d->repeatCount = count;
        QtNativeAndroid::callIntMethod(instance(), "setRepeatCount", count);
        emit repeatCountChanged();
    }
}

QNativeAndroidAnimation::RepeatMode QNativeAndroidAnimation::repeatMode() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->repeatMode.isNull())
        return RESTART;
    return d->repeatMode;
}

void QNativeAndroidAnimation::setRepeatMode(RepeatMode mode)
{
    Q_D(QNativeAndroidAnimation);
    if (d->repeatMode.isNull() || d->repeatMode != mode) {
        d->repeatMode = mode;
        QtNativeAndroid::callIntMethod(instance(), "setRepeatMode", mode);
        emit repeatModeChanged();
    }
}

int QNativeAndroidAnimation::startOffset() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->startOffset.isNull())
        return 0;
    return d->startOffset;
}

void QNativeAndroidAnimation::setStartOffset(int offset)
{
    Q_D(QNativeAndroidAnimation);
    if (d->startOffset.isNull() || d->startOffset != offset) {
        d->startOffset = offset;
        QtNativeAndroid::callIntMethod(instance(), "setStartOffset", offset);
        emit startOffsetChanged();
    }
}

QNativeAndroidAnimation::ZAdjustment QNativeAndroidAnimation::zAdjustment() const
{
    Q_D(const QNativeAndroidAnimation);
    if (d->zAdjustment.isNull())
        return ZORDER_NORMAL;
    return d->zAdjustment;
}

void QNativeAndroidAnimation::setZAdjustment(ZAdjustment adjustment)
{
    Q_D(QNativeAndroidAnimation);
    if (d->zAdjustment.isNull() || d->zAdjustment != adjustment) {
        d->zAdjustment = adjustment;
        QtNativeAndroid::callIntMethod(instance(), "setZAdjustment", adjustment);
        emit zAdjustmentChanged();
    }
}

void QNativeAndroidAnimation::cancel()
{
    QtNativeAndroid::callVoidMethod(instance(), "cancel");
}

void QNativeAndroidAnimation::start()
{
    QtNativeAndroid::callVoidMethod(instance(), "start");
}

void QNativeAndroidAnimation::startNow()
{
    QtNativeAndroid::callVoidMethod(instance(), "startNow");
}

QAndroidJniObject QNativeAndroidAnimation::onCreate()
{
    Q_D(QNativeAndroidAnimation);
    if (d->resource.isNull())
        return QAndroidJniObject("android/view/animation/Animation");

    return QAndroidJniObject::callStaticObjectMethod("android/view/animation/AnimationUtils",
                                                     "loadAnimation",
                                                     "(Landroid/content/Context;I)Landroid/view/animation/Animation;",
                                                     ctx().object(),
                                                     d->resource);
}

void QNativeAndroidAnimation::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidAnimation);
    QNativeAndroidContextual::onInflate(instance);

    if (d->resource.isNull()) {
        if (!d->duration.isNull())
            instance.callMethod<void>("setDuration", "(J)V", static_cast<jlong>(d->duration));
        if (!d->fillAfter.isNull())
            instance.callMethod<void>("setFillAfter", "(Z)V", d->fillAfter);
        if (!d->fillBefore.isNull())
            instance.callMethod<void>("setFillBefore", "(Z)V", d->fillBefore);
        if (!d->fillEnabled.isNull())
            instance.callMethod<void>("setFillEnabled", "(Z)V", d->fillEnabled);
        if (!d->repeatCount.isNull())
            instance.callMethod<void>("setRepeatCount", "(I)V", d->repeatCount);
        if (!d->repeatMode.isNull())
            instance.callMethod<void>("setRepeatMode", "(I)V", d->repeatMode);
        if (!d->startOffset.isNull())
            instance.callMethod<void>("setStartOffset", "(J)V", static_cast<jlong>(d->startOffset));
        if (!d->zAdjustment.isNull())
            instance.callMethod<void>("setZAdjustment", "(I)V", d->zAdjustment);
    }
}

void QNativeAndroidAnimation::objectChange(ObjectChange change)
{
    if (change == InstanceChange)
        updateInterpolator();
}

void QNativeAndroidAnimation::updateInterpolator()
{
    Q_D(QNativeAndroidAnimation);
    if (!isValid() || !d->interpolator || !d->interpolator->isValid())
        return;

    QAndroidJniObject animation = instance();
    QAndroidJniObject interpolator = d->interpolator->instance();
    QtNativeAndroid::callFunction([=]() {
        animation.callMethod<void>("setInterpolator", "(Landroid/view/animation/Interpolator;)V", interpolator.object());
    });
}

QT_END_NAMESPACE
