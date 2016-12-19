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

#ifndef QNATIVEANDROIDARRAYADAPTER_P_H
#define QNATIVEANDROIDARRAYADAPTER_P_H

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

#include <QtNativeAndroid/private/qnativeandroidbaseadapter_p.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidArrayAdapterPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidArrayAdapter : public QNativeAndroidBaseAdapter
{
    Q_OBJECT
    Q_PROPERTY(int style READ style WRITE setStyle NOTIFY styleChanged)
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QNativeAndroidArrayAdapter(QObject *parent = nullptr);

    int style() const;
    void setStyle(int style);

    QStringList array() const;
    void setArray(const QStringList &array);

    int count() const override;
    Q_INVOKABLE QString getItem(int position) const;

public Q_SLOTS:
    void clear() override;

Q_SIGNALS:
    void styleChanged();
    void arrayChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

private:
    Q_DISABLE_COPY(QNativeAndroidArrayAdapter)
    Q_DECLARE_PRIVATE(QNativeAndroidArrayAdapter)
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDARRAYADAPTER_P_H
