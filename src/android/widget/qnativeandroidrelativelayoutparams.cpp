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

#include "qnativeandroidrelativelayoutparams_p.h"
#include "qnativeandroidrelativelayout_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidRelativeLayoutParams::QNativeAndroidRelativeLayoutParams(QNativeAndroidView *view) :
    QNativeAndroidMarginLayoutParams(view),
    m_above(0),
    m_below(0),
    m_alignTop(0),
    m_alignLeft(0),
    m_alignRight(0),
    m_alignBottom(0),
    m_alignStart(0),
    m_alignEnd(0),
    m_alignBaseline(0),
    m_toLeftOf(0),
    m_toRightOf(0),
    m_toStartOf(0),
    m_toEndOf(0),
    m_alignParentTop(false),
    m_alignParentLeft(false),
    m_alignParentRight(false),
    m_alignParentBottom(false),
    m_alignParentStart(false),
    m_alignParentEnd(false),
    m_alignWithParent(false),
    m_centerHorizontal(false),
    m_centerVertical(false),
    m_centerInParent(false)
{
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::above() const
{
    return m_above;
}

void QNativeAndroidRelativeLayoutParams::setAbove(QNativeAndroidView *view)
{
    if (view != m_above) {
        m_above = view;
        invalidate();
        emit aboveChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::below() const
{
    return m_below;
}

void QNativeAndroidRelativeLayoutParams::setBelow(QNativeAndroidView *view)
{
    if (view != m_below) {
        m_below = view;
        invalidate();
        emit belowChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignTop() const
{
    return m_alignTop;
}

void QNativeAndroidRelativeLayoutParams::setAlignTop(QNativeAndroidView *view)
{
    if (view != m_alignTop) {
        m_alignTop = view;
        invalidate();
        emit alignTopChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignLeft() const
{
    return m_alignLeft;
}

void QNativeAndroidRelativeLayoutParams::setAlignLeft(QNativeAndroidView *view)
{
    if (view != m_alignLeft) {
        m_alignLeft = view;
        invalidate();
        emit alignLeftChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignRight() const
{
    return m_alignRight;
}

void QNativeAndroidRelativeLayoutParams::setAlignRight(QNativeAndroidView *view)
{
    if (view != m_alignRight) {
        m_alignRight = view;
        invalidate();
        emit alignRightChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignBottom() const
{
    return m_alignBottom;
}

void QNativeAndroidRelativeLayoutParams::setAlignBottom(QNativeAndroidView *view)
{
    if (view != m_alignBottom) {
        m_alignBottom = view;
        invalidate();
        emit alignBottomChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignStart() const
{
    return m_alignStart;
}

void QNativeAndroidRelativeLayoutParams::setAlignStart(QNativeAndroidView *view)
{
    if (view != m_alignStart) {
        m_alignStart = view;
        invalidate();
        emit alignStartChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignEnd() const
{
    return m_alignEnd;
}

void QNativeAndroidRelativeLayoutParams::setAlignEnd(QNativeAndroidView *view)
{
    if (view != m_alignEnd) {
        m_alignEnd = view;
        invalidate();
        emit alignEndChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignBaseline() const
{
    return m_alignBaseline;
}

void QNativeAndroidRelativeLayoutParams::setAlignBaseline(QNativeAndroidView *view)
{
    if (view != m_alignBaseline) {
        m_alignBaseline = view;
        invalidate();
        emit alignBaselineChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toLeftOf() const
{
    return m_toLeftOf;
}

void QNativeAndroidRelativeLayoutParams::setToLeftOf(QNativeAndroidView *view)
{
    if (view != m_toLeftOf) {
        m_toLeftOf = view;
        invalidate();
        emit toLeftOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toRightOf() const
{
    return m_toRightOf;
}

void QNativeAndroidRelativeLayoutParams::setToRightOf(QNativeAndroidView *view)
{
    if (view != m_toRightOf) {
        m_toRightOf = view;
        invalidate();
        emit toRightOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toStartOf() const
{
    return m_toStartOf;
}

void QNativeAndroidRelativeLayoutParams::setToStartOf(QNativeAndroidView *view)
{
    if (view != m_toStartOf) {
        m_toStartOf = view;
        invalidate();
        emit toStartOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toEndOf() const
{
    return m_toEndOf;
}

void QNativeAndroidRelativeLayoutParams::setToEndOf(QNativeAndroidView *view)
{
    if (view != m_toEndOf) {
        m_toEndOf = view;
        invalidate();
        emit toEndOfChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentTop() const
{
    return m_alignParentTop;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    if (align != alignParentTop()) {
        m_alignParentTop = align;
        invalidate();
        emit alignParentTopChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentLeft() const
{
    return m_alignParentLeft;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    if (align != alignParentLeft()) {
        m_alignParentLeft = align;
        invalidate();
        emit alignParentLeftChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentRight() const
{
    return m_alignParentRight;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    if (align != alignParentRight()) {
        m_alignParentRight = align;
        invalidate();
        emit alignParentRightChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentBottom() const
{
    return m_alignParentBottom;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    if (align != alignParentBottom()) {
        m_alignParentBottom = align;
        invalidate();
        emit alignParentBottomChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentStart() const
{
    return m_alignParentStart;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    if (align != alignParentStart()) {
        m_alignParentStart = align;
        invalidate();
        emit alignParentStartChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentEnd() const
{
    return m_alignParentEnd;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    if (align != alignParentEnd()) {
        m_alignParentEnd = align;
        invalidate();
        emit alignParentEndChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignWithParent() const
{
    return m_alignWithParent;
}

void QNativeAndroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    if (align != alignWithParent()) {
        m_alignWithParent = align;
        invalidate();
        emit alignWithParentChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerHorizontal() const
{
    return m_centerHorizontal;
}

void QNativeAndroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    if (center != centerHorizontal()) {
        m_centerHorizontal = center;
        invalidate();
        emit centerHorizontalChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerVertical() const
{
    return m_centerVertical;
}

void QNativeAndroidRelativeLayoutParams::setCenterVertical(bool center)
{
    if (center != centerVertical()) {
        m_centerVertical = center;
        invalidate();
        emit centerVerticalChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerInParent() const
{
    return m_centerInParent;
}

void QNativeAndroidRelativeLayoutParams::setCenterInParent(bool center)
{
    if (center != centerInParent()) {
        m_centerInParent = center;
        invalidate();
        emit centerInParentChanged();
    }
}

QAndroidJniObject QNativeAndroidRelativeLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/RelativeLayout$LayoutParams",
                             "(II)V",
                             WRAP_CONTENT, WRAP_CONTENT);
}

static void addRule(QAndroidJniObject& instance, QNativeAndroidView *view, QNativeAndroidRelativeLayout::Verb verb)
{
    if (view) {
        int anchor = view->instance().callMethod<jint>("getId");
        instance.callMethod<void>("addRule", "(II)V", verb, anchor);
    }
}

static void addRule(QAndroidJniObject &instance, bool value, QNativeAndroidRelativeLayout::Verb verb)
{
    if (value)
        instance.callMethod<void>("addRule", "(I)V", verb);
}

void QNativeAndroidRelativeLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<jboolean>("alignWithParent", m_alignWithParent);

    addRule(instance, m_above, QNativeAndroidRelativeLayout::ABOVE);
    addRule(instance, m_below, QNativeAndroidRelativeLayout::BELOW);
    addRule(instance, m_alignTop, QNativeAndroidRelativeLayout::ALIGN_TOP);
    addRule(instance, m_alignLeft, QNativeAndroidRelativeLayout::ALIGN_LEFT);
    addRule(instance, m_alignRight, QNativeAndroidRelativeLayout::ALIGN_RIGHT);
    addRule(instance, m_alignBottom, QNativeAndroidRelativeLayout::ALIGN_BOTTOM);
    addRule(instance, m_alignStart, QNativeAndroidRelativeLayout::ALIGN_START);
    addRule(instance, m_alignEnd, QNativeAndroidRelativeLayout::ALIGN_END);
    addRule(instance, m_alignBaseline, QNativeAndroidRelativeLayout::ALIGN_BASELINE);
    addRule(instance, m_toLeftOf, QNativeAndroidRelativeLayout::LEFT_OF);
    addRule(instance, m_toRightOf, QNativeAndroidRelativeLayout::RIGHT_OF);
    addRule(instance, m_toStartOf, QNativeAndroidRelativeLayout::START_OF);
    addRule(instance, m_toEndOf, QNativeAndroidRelativeLayout::END_OF);

    addRule(instance, m_alignParentTop, QNativeAndroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(instance, m_alignParentLeft, QNativeAndroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(instance, m_alignParentRight, QNativeAndroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(instance, m_alignParentBottom, QNativeAndroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(instance, m_alignParentStart, QNativeAndroidRelativeLayout::ALIGN_PARENT_START);
    addRule(instance, m_alignParentEnd, QNativeAndroidRelativeLayout::ALIGN_PARENT_END);
    addRule(instance, m_centerHorizontal, QNativeAndroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(instance, m_centerVertical, QNativeAndroidRelativeLayout::CENTER_VERTICAL);
    addRule(instance, m_centerInParent, QNativeAndroidRelativeLayout::CENTER_IN_PARENT);
}

QT_END_NAMESPACE
