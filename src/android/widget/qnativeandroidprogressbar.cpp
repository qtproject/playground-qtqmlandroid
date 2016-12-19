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

#include "qnativeandroidprogressbar_p.h"
#include "qnativeandroidprogressbar_p_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidProgressBar::QNativeAndroidProgressBar(QNativeAndroidContext *context)
    : QNativeAndroidView(*(new QNativeAndroidProgressBarPrivate), context)
{
}

QNativeAndroidProgressBar::QNativeAndroidProgressBar(QNativeAndroidProgressBarPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidView(dd, context)
{
}

bool QNativeAndroidProgressBar::isIndeterminate() const
{
    Q_D(const QNativeAndroidProgressBar);
    return d->indeterminate;
}

void QNativeAndroidProgressBar::setIndeterminate(bool indeterminate)
{
    Q_D(QNativeAndroidProgressBar);
    if (d->indeterminate != indeterminate) {
        d->indeterminate = indeterminate;
        QtNativeAndroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QNativeAndroidProgressBar::progress() const
{
    Q_D(const QNativeAndroidProgressBar);
    return d->progress;
}

void QNativeAndroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtNativeAndroid::callIntMethod(instance(), "setProgress", progress);
}

bool QNativeAndroidProgressBar::updateProgress(int progress)
{
    Q_D(QNativeAndroidProgressBar);
    if (d->progress != progress) {
        d->progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QNativeAndroidProgressBar::secondaryProgress() const
{
    Q_D(const QNativeAndroidProgressBar);
    return d->secondary;
}

void QNativeAndroidProgressBar::setSecondaryProgress(int progress)
{
    Q_D(QNativeAndroidProgressBar);
    if (d->secondary != progress) {
        d->secondary = progress;
        QtNativeAndroid::callIntMethod(instance(), "setSecondaryProgress", progress);
        emit secondaryProgressChanged();
    }
}

int QNativeAndroidProgressBar::max() const
{
    Q_D(const QNativeAndroidProgressBar);
    return d->max;
}

void QNativeAndroidProgressBar::setMax(int max)
{
    Q_D(QNativeAndroidProgressBar);
    if (d->max != max) {
        d->max = max;
        QtNativeAndroid::callIntMethod(instance(), "setMax", max);
        emit maxChanged();
    }
}

QNativeAndroidProgressBar::Style QNativeAndroidProgressBar::style() const
{
    Q_D(const QNativeAndroidProgressBar);
    if (d->style.isNull())
        return Medium;
    return d->style;
}

void QNativeAndroidProgressBar::setStyle(Style style)
{
    Q_D(QNativeAndroidProgressBar);
    d->style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QNativeAndroidProgressBar::onCreate()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QNativeAndroidProgressBar::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidProgressBar);
    QNativeAndroidView::onInflate(instance);

    if (d->progress > 0)
        instance.callMethod<void>("setProgress", "(I)V", d->progress);
    if (d->secondary > 0)
        instance.callMethod<void>("setSecondaryProgress", "(I)V", d->secondary);
    if (d->indeterminate)
        instance.callMethod<void>("setIndeterminate", "(Z)V", d->indeterminate);
    if (d->max != 100)
        instance.callMethod<void>("setMax", "(I)V", d->max);
}

QT_END_NAMESPACE
