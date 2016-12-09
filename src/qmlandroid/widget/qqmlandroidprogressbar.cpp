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

#include "qqmlandroidprogressbar_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidProgressBar::QQmlAndroidProgressBar(QQmlAndroidView *parent) :
    QQmlAndroidView(parent), m_max(100), m_progress(0), m_secondary(0), m_indeterminate(false)
{
}

bool QQmlAndroidProgressBar::isIndeterminate() const
{
    return m_indeterminate;
}

void QQmlAndroidProgressBar::setIndeterminate(bool indeterminate)
{
    if (m_indeterminate != indeterminate) {
        m_indeterminate = indeterminate;
        QtQmlAndroid::callBoolMethod(instance(), "setIndeterminate", indeterminate);
        emit indeterminateChanged();
    }
}

int QQmlAndroidProgressBar::progress() const
{
    return m_progress;
}

void QQmlAndroidProgressBar::setProgress(int progress)
{
    if (updateProgress(progress))
        QtQmlAndroid::callIntMethod(instance(), "setProgress", progress);
}

bool QQmlAndroidProgressBar::updateProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
        return true;
    }
    return false;
}

int QQmlAndroidProgressBar::secondaryProgress() const
{
    return m_secondary;
}

void QQmlAndroidProgressBar::setSecondaryProgress(int progress)
{
    if (m_secondary != progress) {
        m_secondary = progress;
        QtQmlAndroid::callIntMethod(instance(), "setSecondaryProgress", progress);
        emit secondaryProgressChanged();
    }
}

int QQmlAndroidProgressBar::max() const
{
    return m_max;
}

void QQmlAndroidProgressBar::setMax(int max)
{
    if (m_max != max) {
        m_max = max;
        QtQmlAndroid::callIntMethod(instance(), "setMax", max);
        emit maxChanged();
    }
}

QQmlAndroidProgressBar::Style QQmlAndroidProgressBar::style() const
{
    if (m_style.isNull())
        return Medium;
    return m_style;
}

void QQmlAndroidProgressBar::setStyle(Style style)
{
    m_style = style; // TODO: warning after construction or re-construct?
}

QAndroidJniObject QQmlAndroidProgressBar::onCreate()
{
    return QAndroidJniObject("android/widget/ProgressBar",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;I)V",
                             ctx().object(), 0, style());
}

void QQmlAndroidProgressBar::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);

    if (m_progress > 0)
        instance.callMethod<void>("setProgress", "(I)V", m_progress);
    if (m_secondary > 0)
        instance.callMethod<void>("setSecondaryProgress", "(I)V", m_secondary);
    if (m_indeterminate)
        instance.callMethod<void>("setIndeterminate", "(Z)V", m_indeterminate);
    if (m_max != 100)
        instance.callMethod<void>("setMax", "(I)V", m_max);
}

QT_END_NAMESPACE
