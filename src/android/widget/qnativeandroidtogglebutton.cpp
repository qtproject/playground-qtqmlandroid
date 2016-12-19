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

#include "qnativeandroidtogglebutton_p.h"
#include "qnativeandroidcompoundbutton_p_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidToggleButtonPrivate : public QNativeAndroidCompoundButtonPrivate
{
public:
    QString textOn;
    QString textOff;
};

QNativeAndroidToggleButton::QNativeAndroidToggleButton(QNativeAndroidContext *context)
    : QNativeAndroidCompoundButton(*(new QNativeAndroidToggleButtonPrivate), context)
{
}

QString QNativeAndroidToggleButton::textOn() const
{
    Q_D(const QNativeAndroidToggleButton);
    return d->textOn;
}

void QNativeAndroidToggleButton::setTextOn(const QString &text)
{
    Q_D(QNativeAndroidToggleButton);
    if (d->textOn != text) {
        d->textOn = text;
        QtNativeAndroid::callTextMethod(instance(), "setTextOn", text);
        emit textOnChanged();
    }
}

QString QNativeAndroidToggleButton::textOff() const
{
    Q_D(const QNativeAndroidToggleButton);
    return d->textOff;
}

void QNativeAndroidToggleButton::setTextOff(const QString &text)
{
    Q_D(QNativeAndroidToggleButton);
    if (d->textOff != text) {
        d->textOff = text;
        QtNativeAndroid::callTextMethod(instance(), "setTextOff", text);
        emit textOffChanged();
    }
}

QAndroidJniObject QNativeAndroidToggleButton::onCreate()
{
    return QAndroidJniObject("android/widget/ToggleButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidToggleButton::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidToggleButton);
    QNativeAndroidCompoundButton::onInflate(instance);

    if (!d->textOn.isNull())
        instance.callMethod<void>("setTextOn", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(d->textOn).object());
    if (!d->textOff.isNull())
        instance.callMethod<void>("setTextOff", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(d->textOff).object());
}

QT_END_NAMESPACE
