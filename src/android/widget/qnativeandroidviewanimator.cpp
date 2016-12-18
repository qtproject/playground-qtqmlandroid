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

#include "qnativeandroidviewanimator_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidViewAnimator::QNativeAndroidViewAnimator(QNativeAndroidContext *context) :
    QNativeAndroidFrameLayout(context)
{
}

int QNativeAndroidViewAnimator::displayedChild() const
{
    if (m_displayedChild.isNull())
        return 0;
    return m_displayedChild;
}

void QNativeAndroidViewAnimator::setDisplayedChild(int child)
{
    if (child != displayedChild()) {
        m_displayedChild = child;
        QtQmlAndroid::callIntMethod(instance(), "setDisplayedChild", child);
        emit displayedChildChanged();
    }
}

int QNativeAndroidViewAnimator::inAnimation() const
{
    if (m_inAnimation.isNull())
        return -1;
    return m_inAnimation;
}

void QNativeAndroidViewAnimator::setInAnimation(int animation)
{
    if (animation != inAnimation()) {
        m_inAnimation = animation;
        if (instance().isValid()) {
            QtQmlAndroid::callFunction([=]() {
                instance().callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtQmlAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

int QNativeAndroidViewAnimator::outAnimation() const
{
    if (m_outAnimation.isNull())
        return -1;
    return m_outAnimation;
}

void QNativeAndroidViewAnimator::setOutAnimation(int animation)
{
    if (animation != outAnimation()) {
        m_outAnimation = animation;
        if (instance().isValid()) {
            QtQmlAndroid::callFunction([=]() {
                instance().callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), animation);
            });
        }
        QtQmlAndroid::callIntMethod(instance(), "setInAnimation", animation);
        emit inAnimationChanged();
    }
}

void QNativeAndroidViewAnimator::showNext()
{
    QtQmlAndroid::callVoidMethod(instance(), "showNext");
}

void QNativeAndroidViewAnimator::showPrevious()
{
    QtQmlAndroid::callVoidMethod(instance(), "showPrevious");
}

QAndroidJniObject QNativeAndroidViewAnimator::onCreate()
{
    return QAndroidJniObject("android/widget/ViewAnimator",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidViewAnimator::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidFrameLayout::onInflate(instance);

    if (!m_displayedChild.isNull())
        instance.callMethod<void>("setDisplayedChild", "(I)V", m_displayedChild);
    if (!m_inAnimation.isNull())
        instance.callMethod<void>("setInAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_inAnimation);
    if (!m_outAnimation.isNull())
        instance.callMethod<void>("setOutAnimation", "(Landroid/content/Context;I)V", ctx().object(), m_outAnimation);
}

QT_END_NAMESPACE
