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

#ifndef QNATIVEANDROIDTABSPEC_P_H
#define QNATIVEANDROIDTABSPEC_P_H

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

#include <QtQmlAndroid/private/qtqmlandroidglobal_p.h>

#include <QtCore/qobject.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidView;
class QNativeAndroidTabHost;

class Q_QMLANDROID_EXPORT QNativeAndroidTabSpec : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)

public:
    explicit QNativeAndroidTabSpec(QNativeAndroidView *view);

    static QNativeAndroidTabSpec *qmlAttachedProperties(QObject *object);

    QString label() const;
    void setLabel(const QString &label);

    void setup(QAndroidJniObject &host, int index);

Q_SIGNALS:
    void labelChanged();

private:
    QString m_label;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QNativeAndroidTabSpec, QML_HAS_ATTACHED_PROPERTIES)

#endif // QNATIVEANDROIDTABSPEC_P_H