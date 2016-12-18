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

#ifndef QNATIVEANDROIDROTATEANIMATION_P_H
#define QNATIVEANDROIDROTATEANIMATION_P_H

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

#include <QtNativeAndroid/private/qnativeandroidanimation_p.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidRotateAnimationPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidRotateAnimation : public QNativeAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromDegrees READ fromDegrees WRITE setFromDegrees NOTIFY fromDegreesChanged)
    Q_PROPERTY(qreal toDegrees READ toDegrees WRITE setToDegrees NOTIFY toDegreesChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(Relation pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(Relation pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)
    Q_ENUMS(Relation)

public:
    explicit QNativeAndroidRotateAnimation(QObject *parent = nullptr);

    qreal fromDegrees() const;
    void setFromDegrees(qreal degrees);

    qreal toDegrees() const;
    void setToDegrees(qreal degrees);

    qreal pivotX() const;
    void setPivotX(qreal x);

    qreal pivotY() const;
    void setPivotY(qreal y);

    Relation pivotXType() const;
    void setPivotXType(Relation type);

    Relation pivotYType() const;
    void setPivotYType(Relation type);

Q_SIGNALS:
    void fromDegreesChanged();
    void toDegreesChanged();
    void pivotXChanged();
    void pivotYChanged();
    void pivotXTypeChanged();
    void pivotYTypeChanged();

protected:
    QAndroidJniObject onCreate() override;

private:
    Q_DISABLE_COPY(QNativeAndroidRotateAnimation)
    Q_DECLARE_PRIVATE(QNativeAndroidRotateAnimation)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDROTATEANIMATION_P_H
