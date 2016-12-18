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

#ifndef QNATIVEANDROIDSCALEANIMATION_P_H
#define QNATIVEANDROIDSCALEANIMATION_P_H

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

class QNativeAndroidScaleAnimationPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidScaleAnimation : public QNativeAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromXScale READ fromXScale WRITE setFromXScale NOTIFY fromXScaleChanged)
    Q_PROPERTY(qreal fromYScale READ fromYScale WRITE setFromYScale NOTIFY fromYScaleChanged)
    Q_PROPERTY(qreal toXScale READ toXScale WRITE setToXScale NOTIFY toXScaleChanged)
    Q_PROPERTY(qreal toYScale READ toYScale WRITE setToYScale NOTIFY toYScaleChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(Relation pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(Relation pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)

public:
    explicit QNativeAndroidScaleAnimation(QObject *parent = nullptr);

    qreal fromXScale() const;
    void setFromXScale(qreal scale);

    qreal fromYScale() const;
    void setFromYScale(qreal scale);

    qreal toXScale() const;
    void setToXScale(qreal scale);

    qreal toYScale() const;
    void setToYScale(qreal scale);

    qreal pivotX() const;
    void setPivotX(qreal x);

    qreal pivotY() const;
    void setPivotY(qreal y);

    Relation pivotXType() const;
    void setPivotXType(Relation type);

    Relation pivotYType() const;
    void setPivotYType(Relation type);

Q_SIGNALS:
    void fromXScaleChanged();
    void fromYScaleChanged();
    void toXScaleChanged();
    void toYScaleChanged();
    void pivotXChanged();
    void pivotYChanged();
    void pivotXTypeChanged();
    void pivotYTypeChanged();

protected:
    QAndroidJniObject onCreate() override;

private:
    Q_DISABLE_COPY(QNativeAndroidScaleAnimation)
    Q_DECLARE_PRIVATE(QNativeAndroidScaleAnimation)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDSCALEANIMATION_P_H
