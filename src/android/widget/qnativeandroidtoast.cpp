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

#include "qnativeandroidtoast_p.h"
#include "qnativeandroidobject_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidoptional_p.h"
#include "qnativeandroidview_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidToastPrivate : public QNativeAndroidObjectPrivate
{
public:
    QString text;
    QNativeAndroidOptional<int> gravity;
};

QNativeAndroidToast::QNativeAndroidToast(QObject *parent)
    : QNativeAndroidObject(*(new QNativeAndroidToastPrivate), parent)
{
}

QString QNativeAndroidToast::text() const
{
    Q_D(const QNativeAndroidToast);
    return d->text;
}

void QNativeAndroidToast::setText(const QString &text)
{
    Q_D(QNativeAndroidToast);
    if (d->text != text) {
        d->text = text;
        emit textChanged();
    }
}

int QNativeAndroidToast::gravity() const
{
    Q_D(const QNativeAndroidToast);
    if (d->gravity.isNull())
        return 0; // TODO
    return d->gravity;
}

void QNativeAndroidToast::setGravity(int value)
{
    Q_D(QNativeAndroidToast);
    if (value != gravity()) {
        d->gravity = value;
        emit gravityChanged();
    }
}

void QNativeAndroidToast::show()
{
    Q_D(QNativeAndroidToast);
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView *>(parent());
    if (!view) {
        qWarning() << "Toast must be in a view.";
        return;
    }

    QAndroidJniObject ctx = view->ctx();
    if (!ctx.isValid()) {
        qWarning() << "Toast is not ready - no context.";
        return;
    }

    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject toast;
        if (!d->text.isNull()) {
            toast = QAndroidJniObject::callStaticObjectMethod("android/widget/Toast",
                                                              "makeText",
                                                              "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;",
                                                              ctx.object(),
                                                              QAndroidJniObject::fromString(d->text).object(),
                                                              0); // TODO: LENGTH_SHORT (0), LENGTH_LONG (1)
        } else {
            toast = QAndroidJniObject("android/widget/Toast",
                                      "(Landroid/content/Context;)V",
                                      ctx.object());
        }
        inflate(toast);

        if (!d->gravity.isNull())
            toast.callMethod<void>("setGravity", "(I)V", d->gravity);

        toast.callMethod<void>("show");
    });
}

void QNativeAndroidToast::cancel()
{
    QtNativeAndroid::callVoidMethod(instance(), "cancel");
}

QT_END_NAMESPACE
