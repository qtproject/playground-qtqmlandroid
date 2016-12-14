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

#ifndef QQMLANDROIDTRANSLATEANIMATION_P_H
#define QQMLANDROIDTRANSLATEANIMATION_P_H

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

#include <QtQmlAndroid/private/qqmlandroidanimation_p.h>

QT_BEGIN_NAMESPACE

class Q_QMLANDROID_EXPORT QQmlAndroidTranslateAnimation : public QQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromX READ fromX WRITE setFromX NOTIFY fromXChanged)
    Q_PROPERTY(qreal fromY READ fromY WRITE setFromY NOTIFY fromYChanged)
    Q_PROPERTY(qreal toX READ toX WRITE setToX NOTIFY toXChanged)
    Q_PROPERTY(qreal toY READ toY WRITE setToY NOTIFY toYChanged)
    Q_PROPERTY(Relation fromXType READ fromXType WRITE setFromXType NOTIFY fromXTypeChanged)
    Q_PROPERTY(Relation fromYType READ fromYType WRITE setFromYType NOTIFY fromYTypeChanged)
    Q_PROPERTY(Relation toXType READ toXType WRITE setToXType NOTIFY toXTypeChanged)
    Q_PROPERTY(Relation toYType READ toYType WRITE setToYType NOTIFY toYTypeChanged)

public:
    explicit QQmlAndroidTranslateAnimation(QObject *parent = 0);

    qreal fromX() const;
    void setFromX(qreal x);

    qreal fromY() const;
    void setFromY(qreal y);

    qreal toX() const;
    void setToX(qreal x);

    qreal toY() const;
    void setToY(qreal y);

    Relation fromXType() const;
    void setFromXType(Relation type);

    Relation fromYType() const;
    void setFromYType(Relation type);

    Relation toXType() const;
    void setToXType(Relation type);

    Relation toYType() const;
    void setToYType(Relation type);

Q_SIGNALS:
    void fromXChanged();
    void fromYChanged();
    void toXChanged();
    void toYChanged();
    void fromXTypeChanged();
    void fromYTypeChanged();
    void toXTypeChanged();
    void toYTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    qreal m_fromX;
    qreal m_fromY;
    qreal m_toX;
    qreal m_toY;
    Relation m_fromXType;
    Relation m_fromYType;
    Relation m_toXType;
    Relation m_toYType;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTRANSLATEANIMATION_P_H
