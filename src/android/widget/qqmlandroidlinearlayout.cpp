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

#include "qqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidLinearLayout::QQmlAndroidLinearLayout(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent)
{
}

QQmlAndroidLinearLayoutParams *QQmlAndroidLinearLayout::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidLinearLayoutParams(view);
    return 0;
}

bool QQmlAndroidLinearLayout::isBaselineAligned() const
{
    if (m_baselineAligned.isNull())
        return true;
    return m_baselineAligned;
}

void QQmlAndroidLinearLayout::setBaselineAligned(bool aligned)
{
    if (aligned != isBaselineAligned()) {
        m_baselineAligned = aligned;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAligned", "(Z)V", aligned);
        emit baselineAlignedChanged();
    }
}

int QQmlAndroidLinearLayout::baselineAlignedChildIndex() const
{
    if (m_baselineAlignedChildIndex.isNull())
        return -1;
    return m_baselineAlignedChildIndex;
}

void QQmlAndroidLinearLayout::setBaselineAlignedChildIndex(int index)
{
    if (index != baselineAlignedChildIndex()) {
        m_baselineAlignedChildIndex = index;
//        if (isValid())
//            jniObject().callMethod<void>("setBaselineAlignedChildIndex", "(I)V", index);
        emit baselineAlignedChildIndexChanged();
    }
}

bool QQmlAndroidLinearLayout::isMeasureWithLargestChildEnabled() const
{
    if (m_measureWithLargestChild.isNull())
        return false;
    return m_measureWithLargestChild;
}

void QQmlAndroidLinearLayout::setMeasureWithLargestChildEnabled(bool enabled)
{
    if (enabled != isMeasureWithLargestChildEnabled()) {
        m_measureWithLargestChild = enabled;
//        if (isValid())
//            jniObject().callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", enabled);
        emit measureWithLargestChildEnabledChanged();
    }
}

QQmlAndroidLinearLayout::Orientation QQmlAndroidLinearLayout::orientation() const
{
    if (m_orientation.isNull())
        return HORIZONTAL;
    return m_orientation;
}

void QQmlAndroidLinearLayout::setOrientation(Orientation value)
{
    if (value != orientation()) {
        m_orientation = value;
//        if (isValid())
//            jniObject().callMethod<void>("setOrientation", "(I)V", value);
        emit orientationChanged();
    }
}

qreal QQmlAndroidLinearLayout::weightSum() const
{
    if (m_weightSum.isNull())
        return -1.0f;
    return m_weightSum;
}

void QQmlAndroidLinearLayout::setWeightSum(qreal sum)
{
    if (sum != weightSum()) {
        m_weightSum = sum;
//        if (isValid())
//            jniObject().callMethod<void>("setWeightSum", "(J)V", sum);
        emit weightSumChanged();
    }
}

QAndroidJniObject QQmlAndroidLinearLayout::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidLinearLayout::onInflate(QAndroidJniObject &instance)
{
    if (!m_baselineAligned.isNull())
        instance.callMethod<void>("setBaselineAligned", "(Z)V", m_baselineAligned);
    if (!m_measureWithLargestChild.isNull())
        instance.callMethod<void>("setMeasureWithLargestChildEnabled", "(Z)V", m_measureWithLargestChild);
    if (!m_orientation.isNull())
        instance.callMethod<void>("setOrientation", "(I)V", m_orientation);
    if (!m_weightSum.isNull())
        instance.callMethod<void>("setWeightSum", "(J)V", m_weightSum);

    QQmlAndroidViewGroup::onInflate(instance);

    if (!m_baselineAlignedChildIndex.isNull())
        instance.callMethod<void>("setBaselineAlignedChildIndex", "(I)V", m_baselineAlignedChildIndex);
}

QT_END_NAMESPACE
