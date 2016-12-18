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
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidcolor_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidTextView::QNativeAndroidTextView(QNativeAndroidContext *context) :
    QNativeAndroidView(context), m_singleLine(false)
{
}

QString QNativeAndroidTextView::text() const
{
    return m_text;
}

void QNativeAndroidTextView::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
        QtQmlAndroid::callTextMethod(instance(), "setText", text);
        emit textChanged();
    }
}

int QNativeAndroidTextView::textColor() const
{
    if (m_textColor.isNull())
        return QNativeAndroidColor::BLACK; // TODO
    return m_textColor;
}

void QNativeAndroidTextView::setTextColor(int color)
{
    if (color != textColor()) {
        m_textColor = color;
        QtQmlAndroid::callIntMethod(instance(), "setTextColor", color);
        emit textColorChanged();
    }
}

qreal QNativeAndroidTextView::textSize() const
{
    if (m_textSize.isNull())
        return -1;
    return m_textSize;
}

void QNativeAndroidTextView::setTextSize(qreal size)
{
    if (size != textSize()) {
        m_textSize = size;
        QtQmlAndroid::callRealMethod(instance(), "setTextSize", size);
        emit textSizeChanged();
    }
}

QString QNativeAndroidTextView::hint() const
{
    return m_hint;
}

void QNativeAndroidTextView::setHint(const QString &hint)
{
    if (m_hint != hint) {
        m_hint = hint;
        QtQmlAndroid::callTextMethod(instance(), "setHint", hint);
        emit hintChanged();
    }
}

bool QNativeAndroidTextView::isSingleLine() const
{
    return m_singleLine;
}

void QNativeAndroidTextView::setSingleLine(bool singleLine)
{
    if (m_singleLine != singleLine) {
        m_singleLine = singleLine;
        QtQmlAndroid::callBoolMethod(instance(), "setSingleLine", singleLine);
        emit singleLineChanged();
    }
}

int QNativeAndroidTextView::inputType() const
{
    if (m_inputType.isNull())
        return 0; // TODO
    return m_inputType;
}

void QNativeAndroidTextView::setInputType(int type)
{
    if (m_inputType.isNull() || m_inputType != type) {
        m_inputType = type;
        QtQmlAndroid::callIntMethod(instance(), "setInputType", type);
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
    QNativeAndroidView::onInflate(instance);

    if (!m_text.isNull())
        instance.callMethod<void>("setText", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_text).object());
    if (!m_textColor.isNull())
        instance.callMethod<void>("setTextColor", "(I)V", m_textColor);
    if (!m_textSize.isNull())
        instance.callMethod<void>("setTextSize", "(F)V", m_textSize);
    if (!m_hint.isNull())
        instance.callMethod<void>("setHint", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_hint).object());
    if (m_singleLine)
        instance.callMethod<void>("setSingleLine");
    if (!m_inputType.isNull())
        instance.callMethod<void>("setInputType", "(I)V", m_inputType);
}

QT_END_NAMESPACE
