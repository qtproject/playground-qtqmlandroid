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
#include "qnativeandroidmarginlayoutparams_p_p.h"
#include "qnativeandroidrelativelayout_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidRelativeLayoutParamsPrivate : public QNativeAndroidMarginLayoutParamsPrivate
{
public:
    QNativeAndroidView *above = nullptr;
    QNativeAndroidView *below = nullptr;
    QNativeAndroidView *alignTop = nullptr;
    QNativeAndroidView *alignLeft = nullptr;
    QNativeAndroidView *alignRight = nullptr;
    QNativeAndroidView *alignBottom = nullptr;
    QNativeAndroidView *alignStart = nullptr;
    QNativeAndroidView *alignEnd = nullptr;
    QNativeAndroidView *alignBaseline = nullptr;
    QNativeAndroidView *toLeftOf = nullptr;
    QNativeAndroidView *toRightOf = nullptr;
    QNativeAndroidView *toStartOf = nullptr;
    QNativeAndroidView *toEndOf = nullptr;

    bool alignParentTop = false;
    bool alignParentLeft = false;
    bool alignParentRight = false;
    bool alignParentBottom = false;
    bool alignParentStart = false;
    bool alignParentEnd = false;
    bool alignWithParent = false;
    bool centerHorizontal = false;
    bool centerVertical = false;
    bool centerInParent = false;
};

QNativeAndroidRelativeLayoutParams::QNativeAndroidRelativeLayoutParams(QNativeAndroidView *view)
    : QNativeAndroidMarginLayoutParams(*(new QNativeAndroidRelativeLayoutParamsPrivate), view)
{
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::above() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->above;
}

void QNativeAndroidRelativeLayoutParams::setAbove(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->above) {
        d->above = view;
        invalidate();
        emit aboveChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::below() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->below;
}

void QNativeAndroidRelativeLayoutParams::setBelow(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->below) {
        d->below = view;
        invalidate();
        emit belowChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignTop() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignTop;
}

void QNativeAndroidRelativeLayoutParams::setAlignTop(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignTop) {
        d->alignTop = view;
        invalidate();
        emit alignTopChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignLeft() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignLeft;
}

void QNativeAndroidRelativeLayoutParams::setAlignLeft(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignLeft) {
        d->alignLeft = view;
        invalidate();
        emit alignLeftChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignRight() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignRight;
}

void QNativeAndroidRelativeLayoutParams::setAlignRight(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignRight) {
        d->alignRight = view;
        invalidate();
        emit alignRightChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignBottom() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignBottom;
}

void QNativeAndroidRelativeLayoutParams::setAlignBottom(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignBottom) {
        d->alignBottom = view;
        invalidate();
        emit alignBottomChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignStart() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignStart;
}

void QNativeAndroidRelativeLayoutParams::setAlignStart(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignStart) {
        d->alignStart = view;
        invalidate();
        emit alignStartChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignEnd() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignEnd;
}

void QNativeAndroidRelativeLayoutParams::setAlignEnd(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignEnd) {
        d->alignEnd = view;
        invalidate();
        emit alignEndChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::alignBaseline() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignBaseline;
}

void QNativeAndroidRelativeLayoutParams::setAlignBaseline(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->alignBaseline) {
        d->alignBaseline = view;
        invalidate();
        emit alignBaselineChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toLeftOf() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->toLeftOf;
}

void QNativeAndroidRelativeLayoutParams::setToLeftOf(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->toLeftOf) {
        d->toLeftOf = view;
        invalidate();
        emit toLeftOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toRightOf() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->toRightOf;
}

void QNativeAndroidRelativeLayoutParams::setToRightOf(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->toRightOf) {
        d->toRightOf = view;
        invalidate();
        emit toRightOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toStartOf() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->toStartOf;
}

void QNativeAndroidRelativeLayoutParams::setToStartOf(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->toStartOf) {
        d->toStartOf = view;
        invalidate();
        emit toStartOfChanged();
    }
}

QNativeAndroidView *QNativeAndroidRelativeLayoutParams::toEndOf() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->toEndOf;
}

void QNativeAndroidRelativeLayoutParams::setToEndOf(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (view != d->toEndOf) {
        d->toEndOf = view;
        invalidate();
        emit toEndOfChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentTop() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentTop;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentTop(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentTop()) {
        d->alignParentTop = align;
        invalidate();
        emit alignParentTopChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentLeft() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentLeft;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentLeft(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentLeft()) {
        d->alignParentLeft = align;
        invalidate();
        emit alignParentLeftChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentRight() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentRight;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentRight(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentRight()) {
        d->alignParentRight = align;
        invalidate();
        emit alignParentRightChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentBottom() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentBottom;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentBottom(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentBottom()) {
        d->alignParentBottom = align;
        invalidate();
        emit alignParentBottomChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentStart() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentStart;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentStart(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentStart()) {
        d->alignParentStart = align;
        invalidate();
        emit alignParentStartChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignParentEnd() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignParentEnd;
}

void QNativeAndroidRelativeLayoutParams::setAlignParentEnd(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignParentEnd()) {
        d->alignParentEnd = align;
        invalidate();
        emit alignParentEndChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::alignWithParent() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->alignWithParent;
}

void QNativeAndroidRelativeLayoutParams::setAlignWithParent(bool align)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (align != alignWithParent()) {
        d->alignWithParent = align;
        invalidate();
        emit alignWithParentChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerHorizontal() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->centerHorizontal;
}

void QNativeAndroidRelativeLayoutParams::setCenterHorizontal(bool center)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (center != centerHorizontal()) {
        d->centerHorizontal = center;
        invalidate();
        emit centerHorizontalChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerVertical() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->centerVertical;
}

void QNativeAndroidRelativeLayoutParams::setCenterVertical(bool center)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (center != centerVertical()) {
        d->centerVertical = center;
        invalidate();
        emit centerVerticalChanged();
    }
}

bool QNativeAndroidRelativeLayoutParams::centerInParent() const
{
    Q_D(const QNativeAndroidRelativeLayoutParams);
    return d->centerInParent;
}

void QNativeAndroidRelativeLayoutParams::setCenterInParent(bool center)
{
    Q_D(QNativeAndroidRelativeLayoutParams);
    if (center != centerInParent()) {
        d->centerInParent = center;
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
    Q_D(QNativeAndroidRelativeLayoutParams);
    QNativeAndroidMarginLayoutParams::onInflate(instance);

    instance.setField<jboolean>("alignWithParent", d->alignWithParent);

    addRule(instance, d->above, QNativeAndroidRelativeLayout::ABOVE);
    addRule(instance, d->below, QNativeAndroidRelativeLayout::BELOW);
    addRule(instance, d->alignTop, QNativeAndroidRelativeLayout::ALIGN_TOP);
    addRule(instance, d->alignLeft, QNativeAndroidRelativeLayout::ALIGN_LEFT);
    addRule(instance, d->alignRight, QNativeAndroidRelativeLayout::ALIGN_RIGHT);
    addRule(instance, d->alignBottom, QNativeAndroidRelativeLayout::ALIGN_BOTTOM);
    addRule(instance, d->alignStart, QNativeAndroidRelativeLayout::ALIGN_START);
    addRule(instance, d->alignEnd, QNativeAndroidRelativeLayout::ALIGN_END);
    addRule(instance, d->alignBaseline, QNativeAndroidRelativeLayout::ALIGN_BASELINE);
    addRule(instance, d->toLeftOf, QNativeAndroidRelativeLayout::LEFT_OF);
    addRule(instance, d->toRightOf, QNativeAndroidRelativeLayout::RIGHT_OF);
    addRule(instance, d->toStartOf, QNativeAndroidRelativeLayout::START_OF);
    addRule(instance, d->toEndOf, QNativeAndroidRelativeLayout::END_OF);

    addRule(instance, d->alignParentTop, QNativeAndroidRelativeLayout::ALIGN_PARENT_TOP);
    addRule(instance, d->alignParentLeft, QNativeAndroidRelativeLayout::ALIGN_PARENT_LEFT);
    addRule(instance, d->alignParentRight, QNativeAndroidRelativeLayout::ALIGN_PARENT_RIGHT);
    addRule(instance, d->alignParentBottom, QNativeAndroidRelativeLayout::ALIGN_PARENT_BOTTOM);
    addRule(instance, d->alignParentStart, QNativeAndroidRelativeLayout::ALIGN_PARENT_START);
    addRule(instance, d->alignParentEnd, QNativeAndroidRelativeLayout::ALIGN_PARENT_END);
    addRule(instance, d->centerHorizontal, QNativeAndroidRelativeLayout::CENTER_HORIZONTAL);
    addRule(instance, d->centerVertical, QNativeAndroidRelativeLayout::CENTER_VERTICAL);
    addRule(instance, d->centerInParent, QNativeAndroidRelativeLayout::CENTER_IN_PARENT);
}

QT_END_NAMESPACE
