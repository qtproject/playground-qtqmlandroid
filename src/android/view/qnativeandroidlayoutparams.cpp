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

#include "qnativeandroidlayoutparams_p.h"
#include "qnativeandroidlayoutparams_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidLayoutParams::QNativeAndroidLayoutParams(QNativeAndroidView *view)
    : QNativeAndroidObject(*(new QNativeAndroidLayoutParamsPrivate), view)
{
    Q_D(QNativeAndroidLayoutParams);
    d->view = view;
    view->setLayoutParams(this);
}

QNativeAndroidLayoutParams::QNativeAndroidLayoutParams(QNativeAndroidLayoutParamsPrivate &dd, QNativeAndroidView *view)
    : QNativeAndroidObject(dd, view)
{
    Q_D(QNativeAndroidLayoutParams);
    d->view = view;
    view->setLayoutParams(this);
}

QNativeAndroidLayoutParams *QNativeAndroidLayoutParams::qmlAttachedProperties(QObject *object)
{
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView*>(object);
    if (view)
        return new QNativeAndroidLayoutParams(view);
    return 0;
}

int QNativeAndroidLayoutParams::width() const
{
    Q_D(const QNativeAndroidLayoutParams);
    if (d->width.isNull())
        return MATCH_PARENT;
    return d->width;
}

void QNativeAndroidLayoutParams::setWidth(int value)
{
    Q_D(QNativeAndroidLayoutParams);
    if (value != width()) {
        d->width = value;
        invalidate();
        emit widthChanged();
    }
}

int QNativeAndroidLayoutParams::height() const
{
    Q_D(const QNativeAndroidLayoutParams);
    if (d->height.isNull())
        return MATCH_PARENT;
    return d->height;
}

void QNativeAndroidLayoutParams::setHeight(int value)
{
    Q_D(QNativeAndroidLayoutParams);
    if (value != height()) {
        d->height = value;
        invalidate();
        emit heightChanged();
    }
}

void QNativeAndroidLayoutParams::invalidate()
{
    Q_D(QNativeAndroidLayoutParams);
    if (!d->dirty && isValid()) {
        d->dirty = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::LayoutRequest));
    }
}

QAndroidJniObject QNativeAndroidLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QNativeAndroidLayoutParams::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidLayoutParams);
    if (!d->width.isNull())
        instance.setField<int>("width", d->width);
    if (!d->height.isNull())
        instance.setField<int>("height", d->height);
}

bool QNativeAndroidLayoutParams::event(QEvent *event)
{
    Q_D(QNativeAndroidLayoutParams);
    if (event->type() == QEvent::LayoutRequest) {
        if (d->dirty && isValid()) {
            construct();
            d->dirty = false;
        }
    }
    return QNativeAndroidObject::event(event);
}

QT_END_NAMESPACE
