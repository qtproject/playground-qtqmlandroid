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

#include "qnativeandroidlinearlayout_p.h"
#include "qnativeandroidlinearlayout_p_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidLinearLayout::QNativeAndroidLinearLayout(QNativeAndroidContext *context)
    : QNativeAndroidViewGroup(*(new QNativeAndroidLinearLayoutPrivate), context)
{
}

QNativeAndroidLinearLayout::QNativeAndroidLinearLayout(QNativeAndroidLinearLayoutPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidViewGroup(dd, context)
{
}

QNativeAndroidLinearLayoutParams *QNativeAndroidLinearLayout::qmlAttachedProperties(QObject *object)
{
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView*>(object);
    if (view)
        return new QNativeAndroidLinearLayoutParams(view);
    return 0;
}

bool QNativeAndroidLinearLayout::isBaselineAligned() const
{
    Q_D(const QNativeAndroidLinearLayout);
    if (d->baselineAligned.isNull())
        return true;
    return d->baselineAligned;
}

void QNativeAndroidLinearLayout::setBaselineAligned(bool aligned)
{
    Q_D(QNativeAndroidLinearLayout);
    if (aligned != isBaselineAligned()) {
        d->baselineAligned = aligned;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAligned", "(Z)V", aligned);
        emit baselineAlignedChanged();
    }
}

int QNativeAndroidLinearLayout::baselineAlignedChildIndex() const
{
    Q_D(const QNativeAndroidLinearLayout);
    if (d->baselineAlignedChildIndex.isNull())
        return -1;
    return d->baselineAlignedChildIndex;
}

void QNativeAndroidLinearLayout::setBaselineAlignedChildIndex(int index)
{
    Q_D(QNativeAndroidLinearLayout);
    if (index != baselineAlignedChildIndex()) {
        d->baselineAlignedChildIndex = index;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAlignedChildIndex", "(I)V", index);
        emit baselineAlignedChildIndexChanged();
    }
}

bool QNativeAndroidLinearLayout::isMeasureWithLargestChildEnabled() const
{
    Q_D(const QNativeAndroidLinearLayout);
    if (d->measureWithLargestChild.isNull())
        return false;
    return d->measureWithLargestChild;
}

void QNativeAndroidLinearLayout::setMeasureWithLargestChildEnabled(bool enabled)
{
    Q_D(QNativeAndroidLinearLayout);
    if (enabled != isMeasureWithLargestChildEnabled()) {
        d->measureWithLargestChild = enabled;
//        if (isValid())
//            jniObject().callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", enabled);
        emit measureWithLargestChildEnabledChanged();
    }
}

QNativeAndroidLinearLayout::Orientation QNativeAndroidLinearLayout::orientation() const
{
    Q_D(const QNativeAndroidLinearLayout);
    if (d->orientation.isNull())
        return HORIZONTAL;
    return d->orientation;
}

void QNativeAndroidLinearLayout::setOrientation(Orientation value)
{
    Q_D(QNativeAndroidLinearLayout);
    if (value != orientation()) {
        d->orientation = value;
//        if (isValid())
//            jniObject().callMethod<void>("setOrientation", "(I)V", value);
        emit orientationChanged();
    }
}

qreal QNativeAndroidLinearLayout::weightSum() const
{
    Q_D(const QNativeAndroidLinearLayout);
    if (d->weightSum.isNull())
        return -1.0f;
    return d->weightSum;
}

void QNativeAndroidLinearLayout::setWeightSum(qreal sum)
{
    Q_D(QNativeAndroidLinearLayout);
    if (sum != weightSum()) {
        d->weightSum = sum;
//        if (isValid())
//            jniObject().callMethod<void>("setWeightSum", "(J)V", sum);
        emit weightSumChanged();
    }
}

QAndroidJniObject QNativeAndroidLinearLayout::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidLinearLayout::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidLinearLayout);
    if (!d->baselineAligned.isNull())
        instance.callMethod<void>("setBaselineAligned", "(Z)V", d->baselineAligned);
    if (!d->measureWithLargestChild.isNull())
        instance.callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", d->measureWithLargestChild);
    if (!d->orientation.isNull())
        instance.callMethod<void>("setOrientation", "(I)V", d->orientation);
    if (!d->weightSum.isNull())
        instance.callMethod<void>("setWeightSum", "(J)V", d->weightSum);

    QNativeAndroidViewGroup::onInflate(instance);

    if (!d->baselineAlignedChildIndex.isNull())
        instance.callMethod<void>("setBaselineAlignedChildIndex", "(I)V", d->baselineAlignedChildIndex);
}

QT_END_NAMESPACE
