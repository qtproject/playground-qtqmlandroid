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

#include "qnativeandroidlinearlayoutparams_p.h"
#include "qnativeandroidmarginlayoutparams_p_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidLinearLayoutParamsPrivate : public QNativeAndroidMarginLayoutParamsPrivate
{
public:
    QNativeAndroidOptional<int> gravity;
    QNativeAndroidOptional<qreal> weight;
};

QNativeAndroidLinearLayoutParams::QNativeAndroidLinearLayoutParams(QNativeAndroidView *view)
    : QNativeAndroidMarginLayoutParams(*(new QNativeAndroidLinearLayoutParamsPrivate), view)
{
}

int QNativeAndroidLinearLayoutParams::gravity() const
{
    Q_D(const QNativeAndroidLinearLayoutParams);
    if (d->gravity.isNull())
        return 0; // TODO
    return d->gravity;
}

void QNativeAndroidLinearLayoutParams::setGravity(int value)
{
    Q_D(QNativeAndroidLinearLayoutParams);
    if (value != gravity()) {
        d->gravity = value;
        invalidate();
        emit gravityChanged();
    }
}

qreal QNativeAndroidLinearLayoutParams::weight() const
{
    Q_D(const QNativeAndroidLinearLayoutParams);
    if (d->weight.isNull())
        return 0.0; // TODO
    return d->weight;
}

void QNativeAndroidLinearLayoutParams::setWeight(qreal value)
{
    Q_D(QNativeAndroidLinearLayoutParams);
    if (value != weight()) {
        d->weight = value;
        invalidate();
        emit weightChanged();
    }
}

QAndroidJniObject QNativeAndroidLinearLayoutParams::onCreate()
{
    return QAndroidJniObject("android/widget/LinearLayout$LayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QNativeAndroidLinearLayoutParams::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidLinearLayoutParams);
    QNativeAndroidMarginLayoutParams::onInflate(instance);

    if (!d->gravity.isNull())
        instance.setField<jint>("gravity", d->gravity);
    if (!d->weight.isNull())
        instance.setField<jfloat>("weight", d->weight);
}

QT_END_NAMESPACE
