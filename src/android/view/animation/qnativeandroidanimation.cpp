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
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidinterpolator_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidAnimation::QNativeAndroidAnimation(QObject *parent) :
    QNativeAndroidContextual(parent), m_interpolator(0)
{
}

int QNativeAndroidAnimation::resource() const
{
    if (m_resource.isNull())
        return 0;
    return m_resource;
}

void QNativeAndroidAnimation::setResource(int resource)
{
    if (m_resource.isNull() || m_resource != resource) {
        m_resource = resource;
        emit resourceChanged();
    }
}

int QNativeAndroidAnimation::duration() const
{
    if (m_duration.isNull())
        return 0;
    return m_duration;
}

void QNativeAndroidAnimation::setDuration(int duration)
{
    if (m_duration.isNull() || m_duration != duration) {
        m_duration = duration;
        QtNativeAndroid::callIntMethod(instance(), "setDuration", duration);
        emit durationChanged();
    }
}

bool QNativeAndroidAnimation::fillAfter() const
{
    if (m_fillAfter.isNull())
        return false;
    return m_fillAfter;
}

void QNativeAndroidAnimation::setFillAfter(bool fill)
{
    if (m_fillAfter.isNull() || m_fillAfter != fill) {
        m_fillAfter = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillAfter", fill);
        emit fillAfterChanged();
    }
}

bool QNativeAndroidAnimation::fillBefore() const
{
    if (m_fillBefore.isNull())
        return true;
    return m_fillBefore;
}

void QNativeAndroidAnimation::setFillBefore(bool fill)
{
    if (m_fillBefore.isNull() || m_fillBefore != fill) {
        m_fillBefore = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillBefore", fill);
        emit fillBeforeChanged();
    }
}

bool QNativeAndroidAnimation::fillEnabled() const
{
    if (!m_fillEnabled.isNull())
        return false;
    return m_fillEnabled;
}

void QNativeAndroidAnimation::setFillEnabled(bool fill)
{
    if (m_fillEnabled.isNull() || m_fillEnabled != fill) {
        m_fillEnabled = fill;
        QtNativeAndroid::callBoolMethod(instance(), "setFillEnabled", fill);
        emit fillEnabledChanged();
    }
}

QNativeAndroidInterpolator *QNativeAndroidAnimation::interpolator() const
{
    return m_interpolator;
}

void QNativeAndroidAnimation::setInterpolator(QNativeAndroidInterpolator *interpolator)
{
    if (m_interpolator != interpolator) {
        if (m_interpolator) {
            disconnect(m_interpolator, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAnimation::updateInterpolator);
            m_interpolator->destruct();
        }
        m_interpolator = interpolator;
        if (m_interpolator) {
            connect(m_interpolator, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAnimation::updateInterpolator);
            if (isValid())
                m_interpolator->construct();
        }
    }
}

int QNativeAndroidAnimation::repeatCount() const
{
    if (m_repeatCount.isNull())
        return 0;
    return m_repeatCount;
}

void QNativeAndroidAnimation::setRepeatCount(int count)
{
    if (m_repeatCount.isNull() || m_repeatCount != count) {
        m_repeatCount = count;
        QtNativeAndroid::callIntMethod(instance(), "setRepeatCount", count);
        emit repeatCountChanged();
    }
}

QNativeAndroidAnimation::RepeatMode QNativeAndroidAnimation::repeatMode() const
{
    if (m_repeatMode.isNull())
        return RESTART;
    return m_repeatMode;
}

void QNativeAndroidAnimation::setRepeatMode(RepeatMode mode)
{
    if (m_repeatMode.isNull() || m_repeatMode != mode) {
        m_repeatMode = mode;
        QtNativeAndroid::callIntMethod(instance(), "setRepeatMode", mode);
        emit repeatModeChanged();
    }
}

int QNativeAndroidAnimation::startOffset() const
{
    if (m_startOffset.isNull())
        return 0;
    return m_startOffset;
}

void QNativeAndroidAnimation::setStartOffset(int offset)
{
    if (m_startOffset.isNull() || m_startOffset != offset) {
        m_startOffset = offset;
        QtNativeAndroid::callIntMethod(instance(), "setStartOffset", offset);
        emit startOffsetChanged();
    }
}

QNativeAndroidAnimation::ZAdjustment QNativeAndroidAnimation::zAdjustment() const
{
    if (m_zAdjustment.isNull())
        return ZORDER_NORMAL;
    return m_zAdjustment;
}

void QNativeAndroidAnimation::setZAdjustment(ZAdjustment adjustment)
{
    if (m_zAdjustment.isNull() || m_zAdjustment != adjustment) {
        m_zAdjustment = adjustment;
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
    if (m_resource.isNull())
        return QAndroidJniObject("android/view/animation/Animation");

    return QAndroidJniObject::callStaticObjectMethod("android/view/animation/AnimationUtils",
                                                     "loadAnimation",
                                                     "(Landroid/content/Context;I)Landroid/view/animation/Animation;",
                                                     ctx().object(),
                                                     m_resource);
}

void QNativeAndroidAnimation::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidContextual::onInflate(instance);

    if (m_resource.isNull()) {
        if (!m_duration.isNull())
            instance.callMethod<void>("setDuration", "(J)V", static_cast<jlong>(m_duration));
        if (!m_fillAfter.isNull())
            instance.callMethod<void>("setFillAfter", "(Z)V", m_fillAfter);
        if (!m_fillBefore.isNull())
            instance.callMethod<void>("setFillBefore", "(Z)V", m_fillBefore);
        if (!m_fillEnabled.isNull())
            instance.callMethod<void>("setFillEnabled", "(Z)V", m_fillEnabled);
        if (!m_repeatCount.isNull())
            instance.callMethod<void>("setRepeatCount", "(I)V", m_repeatCount);
        if (!m_repeatMode.isNull())
            instance.callMethod<void>("setRepeatMode", "(I)V", m_repeatMode);
        if (!m_startOffset.isNull())
            instance.callMethod<void>("setStartOffset", "(J)V", static_cast<jlong>(m_startOffset));
        if (!m_zAdjustment.isNull())
            instance.callMethod<void>("setZAdjustment", "(I)V", m_zAdjustment);
    }
}

void QNativeAndroidAnimation::objectChange(ObjectChange change)
{
    if (change == InstanceChange)
        updateInterpolator();
}

void QNativeAndroidAnimation::updateInterpolator()
{
    if (!isValid() || !m_interpolator || !m_interpolator->isValid())
        return;

    QAndroidJniObject animation = instance();
    QAndroidJniObject interpolator = m_interpolator->instance();
    QtNativeAndroid::callFunction([=]() {
        animation.callMethod<void>("setInterpolator", "(Landroid/view/animation/Interpolator;)V", interpolator.object());
    });
}

QT_END_NAMESPACE
