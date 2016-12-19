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

#include "qnativeandroidtextview_p.h"
#include "qnativeandroidtextview_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidcolor_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidTextView::QNativeAndroidTextView(QNativeAndroidContext *context)
    : QNativeAndroidView(*(new QNativeAndroidTextViewPrivate), context)
{
}

QNativeAndroidTextView::QNativeAndroidTextView(QNativeAndroidTextViewPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidView(dd, context)
{
}

QString QNativeAndroidTextView::text() const
{
    Q_D(const QNativeAndroidTextView);
    return d->text;
}

void QNativeAndroidTextView::setText(const QString &text)
{
    Q_D(QNativeAndroidTextView);
    if (d->text != text) {
        d->text = text;
        QtNativeAndroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QNativeAndroidTextView::textColor() const
{
    Q_D(const QNativeAndroidTextView);
    if (d->textColor.isNull())
        return QNativeAndroidColor::BLACK; // TODO
    return d->textColor;
}

void QNativeAndroidTextView::setTextColor(int color)
{
    Q_D(QNativeAndroidTextView);
    if (color != textColor()) {
        d->textColor = color;
        QtNativeAndroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QNativeAndroidTextView::textSize() const
{
    Q_D(const QNativeAndroidTextView);
    if (d->textSize.isNull())
        return -1;
    return d->textSize;
}

void QNativeAndroidTextView::setTextSize(qreal size)
{
    Q_D(QNativeAndroidTextView);
    if (size != textSize()) {
        d->textSize = size;
        QtNativeAndroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QNativeAndroidTextView::hint() const
{
    Q_D(const QNativeAndroidTextView);
    return d->hint;
}

void QNativeAndroidTextView::setHint(const QString &hint)
{
    Q_D(QNativeAndroidTextView);
    if (d->hint != hint) {
        d->hint = hint;
        QtNativeAndroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

bool QNativeAndroidTextView::isSingleLine() const
{
    Q_D(const QNativeAndroidTextView);
    return d->singleLine;
}

void QNativeAndroidTextView::setSingleLine(bool singleLine)
{
    Q_D(QNativeAndroidTextView);
    if (d->singleLine != singleLine) {
        d->singleLine = singleLine;
        QtNativeAndroid::callBoolMethod(instance(), "setSingleLine", singleLine);
        emit singleLineChanged();
    }
}

int QNativeAndroidTextView::inputType() const
{
    Q_D(const QNativeAndroidTextView);
    if (d->inputType.isNull())
        return 0; // TODO
    return d->inputType;
}

void QNativeAndroidTextView::setInputType(int type)
{
    Q_D(QNativeAndroidTextView);
    if (d->inputType.isNull() || d->inputType != type) {
        d->inputType = type;
        QtNativeAndroid::callIntMethod(instance(), "setInputType", type);
        emit inputTypeChanged();
    }
}

QAndroidJniObject QNativeAndroidTextView::onCreate()
{
    return QAndroidJniObject("android/widget/TextView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidTextView::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidTextView);
    QNativeAndroidView::onInflate(instance);

    if (!d->text.isNull())
        instance.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(d->text).object());
    if (!d->textColor.isNull())
        instance.callMethod<void>("setTextColor", "(I)V", d->textColor);
    if (!d->textSize.isNull())
        instance.callMethod<void>("setTextSize", "(F)V", d->textSize);
    if (!d->hint.isNull())
        instance.callMethod<void>("setHint", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(d->hint).object());
    if (d->singleLine)
        instance.callMethod<void>("setSingleLine");
    if (!d->inputType.isNull())
        instance.callMethod<void>("setInputType", "(I)V", d->inputType);
}

QT_END_NAMESPACE
