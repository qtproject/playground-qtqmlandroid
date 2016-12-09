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

#ifndef QQMLANDROIDRELATIVELAYOUT_P_H
#define QQMLANDROIDRELATIVELAYOUT_P_H

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

#include <QtQmlAndroid/private/qqmlandroidviewgroup_p.h>
#include <QtQmlAndroid/private/qqmlandroidrelativelayoutparams_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidRelativeLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QQmlAndroidRelativeLayout(QQmlAndroidView *parent = 0);

    static QQmlAndroidRelativeLayoutParams *qmlAttachedProperties(QObject *object);

    enum Verb {
        LEFT_OF                  = 0,
        RIGHT_OF                 = 1,
        ABOVE                    = 2,
        BELOW                    = 3,
        ALIGN_BASELINE           = 4,
        ALIGN_LEFT               = 5,
        ALIGN_TOP                = 6,
        ALIGN_RIGHT              = 7,
        ALIGN_BOTTOM             = 8,
        ALIGN_PARENT_LEFT        = 9,
        ALIGN_PARENT_TOP         = 10,
        ALIGN_PARENT_RIGHT       = 11,
        ALIGN_PARENT_BOTTOM      = 12,
        CENTER_IN_PARENT         = 13,
        CENTER_HORIZONTAL        = 14,
        CENTER_VERTICAL          = 15,
        START_OF                 = 16,
        END_OF                   = 17,
        ALIGN_START              = 18,
        ALIGN_END                = 19,
        ALIGN_PARENT_START       = 20,
        ALIGN_PARENT_END         = 21
    };

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidRelativeLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDRELATIVELAYOUT_P_H
