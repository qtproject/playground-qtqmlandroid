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

#include "qqmlandroidmarginlayoutparams_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidMarginLayoutParams::QQmlAndroidMarginLayoutParams(QQmlAndroidView *view) :
    QQmlAndroidLayoutParams(view)
{
}

int QQmlAndroidMarginLayoutParams::margin() const
{
    if (m_margin.isNull())
        return 0;
    return m_margin;
}

void QQmlAndroidMarginLayoutParams::setMargin(int margin)
{
    if (m_margin.isNull() || m_margin != margin) {
        m_margin = margin;
        invalidate();
        emit marginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::topMargin() const
{
    if (m_topMargin.isNull())
        return margin();
    return m_topMargin;
}

void QQmlAndroidMarginLayoutParams::setTopMargin(int margin)
{
    if (m_topMargin.isNull() || m_topMargin != margin) {
        m_topMargin = margin;
        invalidate();
        emit topMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::leftMargin() const
{
    if (m_leftMargin.isNull())
        return margin();
    return m_leftMargin;
}

void QQmlAndroidMarginLayoutParams::setLeftMargin(int margin)
{
    if (m_leftMargin.isNull() || m_leftMargin != margin) {
        m_leftMargin = margin;
        invalidate();
        emit leftMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::rightMargin() const
{
    if (m_rightMargin.isNull())
        return margin();
    return m_rightMargin;
}

void QQmlAndroidMarginLayoutParams::setRightMargin(int margin)
{
    if (m_rightMargin.isNull() || m_rightMargin != margin) {
        m_rightMargin = margin;
        invalidate();
        emit rightMarginChanged();
    }
}

int QQmlAndroidMarginLayoutParams::bottomMargin() const
{
    if (m_bottomMargin.isNull())
        return margin();
    return m_bottomMargin;
}

void QQmlAndroidMarginLayoutParams::setBottomMargin(int margin)
{
    if (m_bottomMargin.isNull() || m_bottomMargin != margin) {
        m_bottomMargin = margin;
        invalidate();
        emit bottomMarginChanged();
    }
}

QAndroidJniObject QQmlAndroidMarginLayoutParams::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup$MarginLayoutParams",
                             "(II)V",
                             MATCH_PARENT, MATCH_PARENT);
}

void QQmlAndroidMarginLayoutParams::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLayoutParams::onInflate(instance);

    instance.callMethod<void>("setMargins",
                              "(IIII)V",
                              leftMargin(),
                              topMargin(),
                              rightMargin(),
                              bottomMargin());
}

QT_END_NAMESPACE
