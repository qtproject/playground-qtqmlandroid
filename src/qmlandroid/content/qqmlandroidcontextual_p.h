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

#ifndef QQMLANDROIDCONTEXTUAL_P_H
#define QQMLANDROIDCONTEXTUAL_P_H

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

#include <QtQmlAndroid/private/qqmlandroidobject_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidContext;

class Q_QMLANDROID_EXPORT QQmlAndroidContextual : public QQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidContext *context READ context NOTIFY contextChanged)

public:
    explicit QQmlAndroidContextual(QObject *parent = 0);
    explicit QQmlAndroidContextual(QQmlAndroidContext *context, QObject *parent = 0);

    QAndroidJniObject ctx() const;
    QQmlAndroidContext *context() const;
    void setContext(QQmlAndroidContext *context);

Q_SIGNALS:
    void contextChanged();

protected:
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool initContext(QQmlAndroidContext *context = 0);
    void resolveContext();
    void propagateContext();

private:
    QQmlAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCONTEXTUAL_P_H
