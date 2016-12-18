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

#ifndef QNATIVEANDROIDVIEW_P_P_H
#define QNATIVEANDROIDVIEW_P_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtNativeAndroid/private/qnativeandroidcontextual_p_p.h>
#include <QtNativeAndroid/private/qnativeandroidoptional_p.h>
#include <QtNativeAndroid/private/qnativeandroidview_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidViewPrivate : public QNativeAndroidContextualPrivate
{
    Q_DECLARE_PUBLIC(QNativeAndroidView)

public:
    void init();

    int id = 0;
    QNativeAndroidView *parent = nullptr;
    QList<QNativeAndroidView *> children;
    QNativeAndroidDrawable *background = nullptr;
    int backgroundResource = 0;
    QNativeAndroidAnimation *animation = nullptr;
    bool polishing = false;
    bool visible = true;

    QAndroidJniObject listener;

    QNativeAndroidLayoutParams *layoutParams = nullptr;

    QNativeAndroidOptional<bool> focus;
    QNativeAndroidOptional<int> top;
    QNativeAndroidOptional<int> left;
    QNativeAndroidOptional<int> right;
    QNativeAndroidOptional<int> bottom;
    QNativeAndroidOptional<int> padding;
    QNativeAndroidOptional<int> paddingTop;
    QNativeAndroidOptional<int> paddingLeft;
    QNativeAndroidOptional<int> paddingRight;
    QNativeAndroidOptional<int> paddingBottom;
    QNativeAndroidOptional<qreal> alpha;
    QNativeAndroidOptional<qreal> scaleX;
    QNativeAndroidOptional<qreal> scaleY;
    QNativeAndroidOptional<qreal> pivotX;
    QNativeAndroidOptional<qreal> pivotY;
    QNativeAndroidOptional<qreal> rotation;
    QNativeAndroidOptional<qreal> rotationX;
    QNativeAndroidOptional<qreal> rotationY;
    QNativeAndroidOptional<qreal> translationX;
    QNativeAndroidOptional<qreal> translationY;
    QNativeAndroidOptional<qreal> translationZ;
    QNativeAndroidOptional<qreal> elevation;
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDVIEW_P_P_H
