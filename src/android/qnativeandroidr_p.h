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

#ifndef QNATIVEANDROIDR_P_H
#define QNATIVEANDROIDR_P_H

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

#include <QtNativeAndroid/private/qtnativeandroidglobal_p.h>

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QJSEngine;
class QQmlEngine;
class QQmlPropertyMap;
class QNativeAndroidRPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidR : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlPropertyMap *anim READ anim CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *animator READ animator CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *array READ anim CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *attr READ attr CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *boolean READ boolean CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *color READ color CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *dimen READ dimen CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *drawable READ drawable CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *fraction READ fraction CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *id READ id CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *integer READ integer CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *interpolator READ interpolator CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *layout READ layout CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *menu READ menu CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *mipmap READ mipmap CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *plurals READ plurals CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *raw READ raw CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *string READ string CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *style READ style CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *styleable READ styleable CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *transition READ transition CONSTANT)
    Q_PROPERTY(QQmlPropertyMap *xml READ xml CONSTANT)

public:
    explicit QNativeAndroidR(QObject *parent = nullptr);

    QQmlPropertyMap *anim();
    QQmlPropertyMap *animator();
    QQmlPropertyMap *array();
    QQmlPropertyMap *attr();
    QQmlPropertyMap *boolean();
    QQmlPropertyMap *color();
    QQmlPropertyMap *dimen();
    QQmlPropertyMap *drawable();
    QQmlPropertyMap *fraction();
    QQmlPropertyMap *id();
    QQmlPropertyMap *integer();
    QQmlPropertyMap *interpolator();
    QQmlPropertyMap *layout();
    QQmlPropertyMap *menu();
    QQmlPropertyMap *mipmap();
    QQmlPropertyMap *plurals();
    QQmlPropertyMap *raw();
    QQmlPropertyMap *string();
    QQmlPropertyMap *style();
    QQmlPropertyMap *styleable();
    QQmlPropertyMap *transition();
    QQmlPropertyMap *xml();

    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    Q_DISABLE_COPY(QNativeAndroidR)
    Q_DECLARE_PRIVATE(QNativeAndroidR)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDR_P_H
