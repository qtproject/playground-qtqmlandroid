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

#ifndef QNATIVEANDROIDAPATHINTERPOLATOR_P_H
#define QNATIVEANDROIDAPATHINTERPOLATOR_P_H

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

#include <QtNativeAndroid/private/qnativeandroidinterpolator_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidPathInterpolatorPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidPathInterpolator : public QNativeAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal controlX READ controlX WRITE setControlX NOTIFY controlXChanged)
    Q_PROPERTY(qreal controlY READ controlY WRITE setControlY NOTIFY controlYChanged)
    Q_PROPERTY(qreal controlX2 READ controlX2 WRITE setControlX2 NOTIFY controlX2Changed)
    Q_PROPERTY(qreal controlY2 READ controlY2 WRITE setControlY2 NOTIFY controlY2Changed)

public:
    explicit QNativeAndroidPathInterpolator(QObject *parent = nullptr);

    qreal controlX() const;
    void setControlX(qreal x);

    qreal controlY() const;
    void setControlY(qreal y);

    qreal controlX2() const;
    void setControlX2(qreal x);

    qreal controlY2() const;
    void setControlY2(qreal y);

Q_SIGNALS:
    void controlXChanged();
    void controlYChanged();
    void controlX2Changed();
    void controlY2Changed();

protected:
    QAndroidJniObject onCreate() override;

private:
    Q_DISABLE_COPY(QNativeAndroidPathInterpolator)
    Q_DECLARE_PRIVATE(QNativeAndroidPathInterpolator)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDAPATHINTERPOLATOR_P_H
