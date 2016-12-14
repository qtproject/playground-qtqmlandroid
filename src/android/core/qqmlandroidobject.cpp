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

#include "qqmlandroidobject_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>

QT_BEGIN_NAMESPACE

Q_GLOBAL_STATIC(QReadWriteLock, instanceLock)

QQmlAndroidObject::QQmlAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

bool QQmlAndroidObject::isValid() const
{
    QReadLocker locker(instanceLock());
    return m_instance.isValid();
}

QAndroidJniObject QQmlAndroidObject::instance() const
{
    QReadLocker locker(instanceLock());
    return m_instance;
}

void QQmlAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    QWriteLocker locker(instanceLock());
    if (m_instance != instance) {
        m_instance = instance;
        // queue to Qt thread if necessary
        QMetaObject::invokeMethod(this, "changeInstance", Qt::AutoConnection);
    }
}

void QQmlAndroidObject::changeInstance()
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    objectChange(InstanceChange);
    emit instanceChanged();
}

void QQmlAndroidObject::construct()
{
    foreach (QObject *obj, children()) {
        QQmlAndroidObject *child = qobject_cast<QQmlAndroidObject *>(obj);
        if (child)
            child->construct();
    }

    std::function<void()> method = [=]() {
        inflate(onCreate());
    };

    if (QtQmlAndroid::isMainQtThread())
        QtQmlAndroid::callFunction(method);
    else
        method();
}

void QQmlAndroidObject::inflate(const QAndroidJniObject &instance)
{
    std::function<void()> method = [=]() {
        QAndroidJniObject object(instance);
        if (object.isValid())
            onInflate(object);
        setInstance(object);
    };

    if (QtQmlAndroid::isMainQtThread())
        QtQmlAndroid::callFunction(method);
    else
        method();
}

void QQmlAndroidObject::destruct()
{
    foreach (QObject *obj, children()) {
        QQmlAndroidObject *child = qobject_cast<QQmlAndroidObject *>(obj);
        if (child)
            child->destruct();
    }

    setInstance(QAndroidJniObject());
}

QAndroidJniObject QQmlAndroidObject::onCreate()
{
    return QAndroidJniObject();
}

void QQmlAndroidObject::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());
}

bool QQmlAndroidObject::isComponentComplete() const
{
    return m_complete;
}

void QQmlAndroidObject::classBegin()
{
}

void QQmlAndroidObject::componentComplete()
{
    m_complete = true;
}

void QQmlAndroidObject::objectChange(ObjectChange change)
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    Q_UNUSED(change);
}

QQmlListProperty<QObject> QQmlAndroidObject::data()
{
    return QQmlListProperty<QObject>(this, 0, &QQmlAndroidObject::data_append,
                                     &QQmlAndroidObject::data_count, &QQmlAndroidObject::data_at, 0);
}

void QQmlAndroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        object->setParent(that);
}

int QQmlAndroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        return that->children().count();
    return 0;
}

QObject *QQmlAndroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        return that->children().value(index);
    return 0;
}

void QQmlAndroidObject::childEvent(QChildEvent *event)
{
    if (event->added())
        emit dataChanged();
    else if (event->removed())
        emit dataChanged();
}

QT_END_NAMESPACE
