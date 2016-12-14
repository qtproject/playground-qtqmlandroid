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

#include "qqmlandroidcontextual_p.h"
#include "qqmlandroidcontext_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QQmlAndroidContextual::QQmlAndroidContextual(QObject *parent) :
    QQmlAndroidObject(parent), m_context(0)
{
    if (!initContext())
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QQmlAndroidContextual::QQmlAndroidContextual(QQmlAndroidContext* context, QObject *parent) :
    QQmlAndroidObject(parent), m_context(0)
{
    if (!initContext(context))
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QAndroidJniObject QQmlAndroidContextual::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QQmlAndroidContext *QQmlAndroidContextual::context() const
{
    return m_context;
}

void QQmlAndroidContextual::setContext(QQmlAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        propagateContext();
        emit contextChanged();
    }
}

void QQmlAndroidContextual::componentComplete()
{
    QQmlAndroidObject::componentComplete();
    propagateContext();
}

static QQmlAndroidContext *findContext(QQmlAndroidObject *object)
{
    QQmlAndroidContext *context = qobject_cast<QQmlAndroidContext *>(object);
    QObject *p = object->parent();
    while (p && !context) {
        QQmlAndroidContextual *contextual = qobject_cast<QQmlAndroidContextual *>(p);
        if (contextual)
            context = contextual->context();
        p = p->parent();
    }
    return context;
}

bool QQmlAndroidContextual::initContext(QQmlAndroidContext *context)
{
    if (!context)
        context = findContext(this);
    setContext(context);
    return context;
}

void QQmlAndroidContextual::resolveContext()
{
    if (!m_context) {
        setContext(findContext(this));
        if (!m_context)
            qWarning() << "QQmlAndroidContextual: could not resolve context for" << this;
    }
}

void QQmlAndroidContextual::propagateContext()
{
    foreach (QObject *child, children()) {
        QQmlAndroidContextual *contextual = qobject_cast<QQmlAndroidContextual *>(child);
        if (contextual)
            contextual->setContext(m_context);
    }
}

QT_END_NAMESPACE
