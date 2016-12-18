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

#ifndef QNATIVEANDROIDOBJECT_P_H
#define QNATIVEANDROIDOBJECT_P_H

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
#include <QtQml/qqmllist.h>
#include <QtQml/qqmlparserstatus.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidObjectPrivate;

class Q_NATIVEANDROID_EXPORT QNativeAndroidObject : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QNativeAndroidObject(QObject *parent = nullptr);

    bool isValid() const;
    QAndroidJniObject instance() const;

    void construct();
    void inflate(const QAndroidJniObject &instance);
    void destruct();

    QQmlListProperty<QObject> data();

    enum ObjectChange {
        InstanceChange
    };

Q_SIGNALS:
    void dataChanged();
    void instanceChanged();

protected:
    QNativeAndroidObject(QNativeAndroidObjectPrivate &dd, QObject *parent = nullptr);

    virtual QAndroidJniObject onCreate();
    virtual void onInflate(QAndroidJniObject &instance);

    bool isComponentComplete() const;
    void classBegin() override;
    void componentComplete() override;

    virtual void objectChange(ObjectChange change);

    static void data_append(QQmlListProperty<QObject> *list, QObject *object);
    static int data_count(QQmlListProperty<QObject> *list);
    static QObject *data_at(QQmlListProperty<QObject> *list, int index);

    void childEvent(QChildEvent *event) override;

private Q_SLOTS:
    void changeInstance();

private:
    Q_DISABLE_COPY(QNativeAndroidObject)
    Q_DECLARE_PRIVATE(QNativeAndroidObject)

    void setInstance(const QAndroidJniObject &instance);
    friend class QNativeAndroidActivity;
};

QT_END_NAMESPACE

#endif // QNATIVEANDROIDOBJECT_P_H
