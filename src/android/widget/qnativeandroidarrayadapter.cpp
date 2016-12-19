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

#include "qnativeandroidarrayadapter_p.h"
#include "qnativeandroidbaseadapter_p_p.h"
#include "qnativeandroidadapterview_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidArrayAdapterPrivate : public QNativeAndroidBaseAdapterPrivate
{
public:
    int style = 17367043; // TODO: android.R.layout.simple_list_item_1
    QStringList array;
};

QNativeAndroidArrayAdapter::QNativeAndroidArrayAdapter(QObject *parent)
    : QNativeAndroidBaseAdapter(*(new QNativeAndroidArrayAdapterPrivate), parent)
{
}

int QNativeAndroidArrayAdapter::style() const
{
    Q_D(const QNativeAndroidArrayAdapter);
    return d->style;
}

void QNativeAndroidArrayAdapter::setStyle(int style)
{
    Q_D(QNativeAndroidArrayAdapter);
    if (d->style != style) {
        d->style = style;
        emit styleChanged();
    }
}

QStringList QNativeAndroidArrayAdapter::array() const
{
    Q_D(const QNativeAndroidArrayAdapter);
    return d->array;
}

void QNativeAndroidArrayAdapter::setArray(const QStringList &array)
{
    Q_D(QNativeAndroidArrayAdapter);
    if (d->array != array) {
        d->array = array; // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

int QNativeAndroidArrayAdapter::count() const
{
    Q_D(const QNativeAndroidArrayAdapter);
    return d->array.count();
}

QString QNativeAndroidArrayAdapter::getItem(int position) const
{
    Q_D(const QNativeAndroidArrayAdapter);
    return d->array.value(position);
}

void QNativeAndroidArrayAdapter::clear()
{
    Q_D(QNativeAndroidArrayAdapter);
    if (!d->array.isEmpty()) {
        d->array.clear(); // TODO: sync
        emit countChanged();
        emit arrayChanged();
    }
}

QAndroidJniObject QNativeAndroidArrayAdapter::onCreate()
{
    Q_D(QNativeAndroidArrayAdapter);
    return QAndroidJniObject("android/widget/ArrayAdapter",
                             "(Landroid/content/Context;I)V",
                             ctx().object(),
                             d->style);
}

void QNativeAndroidArrayAdapter::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidArrayAdapter);
    QNativeAndroidBaseAdapter::onInflate(instance);

    foreach (const QString &str, d->array)
        instance.callMethod<void>("add", "(Ljava/lang/Object;)V", QAndroidJniObject::fromString(str).object());
}

QT_END_NAMESPACE
