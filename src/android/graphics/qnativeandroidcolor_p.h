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

#ifndef QNATIVEANDROIDCOLOR_P_H
#define QNATIVEANDROIDCOLOR_P_H

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
#include <QtQml/qqmlengine.h>

QT_BEGIN_NAMESPACE

class Q_NATIVEANDROID_EXPORT QNativeAndroidColor : public QObject
{
    Q_OBJECT
    Q_ENUMS(Constants)

public:
    enum Constants {
        BLACK       = 0xFF000000,
        DKGRAY      = 0xFF444444,
        GRAY        = 0xFF888888,
        LTGRAY      = 0xFFCCCCCC,
        WHITE       = 0xFFFFFFFF,
        RED         = 0xFFFF0000,
        GREEN       = 0xFF00FF00,
        BLUE        = 0xFF0000FF,
        YELLOW      = 0xFFFFFF00,
        CYAN        = 0xFF00FFFF,
        MAGENTA     = 0xFFFF00FF,
        TRANSPARENT = 0
    };

    Q_INVOKABLE static int alpha(int color);
    Q_INVOKABLE static int argb(int alpha, int red, int green, int blue);
    Q_INVOKABLE static int blue(int color);
    Q_INVOKABLE static int green(int color);
    Q_INVOKABLE static int red(int color);
    Q_INVOKABLE static int rgb(int red, int green, int blue);
    Q_INVOKABLE static int name(const QString &name);

    static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDCOLOR_P_H
