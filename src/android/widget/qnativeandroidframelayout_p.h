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

#ifndef QNATIVEANDROIDFRAMELAYOUT_P_H
#define QNATIVEANDROIDFRAMELAYOUT_P_H

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

#include <QtNativeAndroid/private/qnativeandroidviewgroup_p.h>
#include <QtNativeAndroid/private/qnativeandroidframelayoutparams_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidFrameLayoutPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidFrameLayout : public QNativeAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QNativeAndroidFrameLayout(QNativeAndroidContext *context = nullptr);

    static QNativeAndroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QNativeAndroidFrameLayout(QNativeAndroidFrameLayoutPrivate &dd, QNativeAndroidContext *context = nullptr);

    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private:
    Q_DISABLE_COPY(QNativeAndroidFrameLayout)
    Q_DECLARE_PRIVATE(QNativeAndroidFrameLayout)
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QNativeAndroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QNATIVEANDROIDFRAMELAYOUT_P_H
