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

#include "qqmlandroidadapterview_p.h"
#include "qqmlandroidbaseadapter_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAdapterView::QQmlAndroidAdapterView(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent), m_adapter(0)
{
}

QQmlAndroidBaseAdapter *QQmlAndroidAdapterView::adapter() const
{
    return m_adapter;
}

void QQmlAndroidAdapterView::setAdapter(QQmlAndroidBaseAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAdapterView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidAdapterView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }
}

void QQmlAndroidAdapterView::setSelection(int position)
{
    QtQmlAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QQmlAndroidAdapterView::onCreate()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidAdapterView::onInflate(QAndroidJniObject &instance)
{
    m_listener = QAndroidJniObject("qt/android/widget/QmlAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    QQmlAndroidViewGroup::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QQmlAndroidAdapterView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidAdapterView *view = reinterpret_cast<QQmlAndroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}

void QQmlAndroidAdapterView::objectChange(ObjectChange change)
{
    QQmlAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QQmlAndroidAdapterView::updateAdapter()
{
    if (!isValid())
        return;

    QAndroidJniObject adapter;
    if (m_adapter)
        adapter = m_adapter->instance();

    QAndroidJniObject view = instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/widget/Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
