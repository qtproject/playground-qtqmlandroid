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

#include "qnativeandroidswiperefreshlayout_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidSwipeRefreshLayout::QNativeAndroidSwipeRefreshLayout(QNativeAndroidView *parent) :
    QNativeAndroidViewGroup(parent), m_refreshing(false)
{
}

bool QNativeAndroidSwipeRefreshLayout::isRefreshing() const
{
    return m_refreshing;
}

void QNativeAndroidSwipeRefreshLayout::setRefreshing(bool refreshing)
{
    if (updateRefreshing(refreshing))
        QtQmlAndroid::callBoolMethod(instance(), "setRefreshing", refreshing);
}

bool QNativeAndroidSwipeRefreshLayout::updateRefreshing(bool refreshing)
{
    if (m_refreshing != refreshing) {
        m_refreshing = refreshing;
        emit refreshingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QNativeAndroidSwipeRefreshLayout::onCreate()
{
    return QAndroidJniObject("android/support/v4/widget/SwipeRefreshLayout",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidSwipeRefreshLayout::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidViewGroup::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/support/v4/widget/QmlSwipeRefreshLayoutListener",
                                   "(Landroid/support/v4/widget/SwipeRefreshLayout;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidSwipeRefreshLayout::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRefresh", "(J)V", reinterpret_cast<void *>(onRefresh)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidSwipeRefreshLayout::onRefresh(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidSwipeRefreshLayout *layout = reinterpret_cast<QNativeAndroidSwipeRefreshLayout *>(instance);
    if (layout)
        QMetaObject::invokeMethod(layout, "updateRefreshing", Qt::QueuedConnection, Q_ARG(bool, true));
}

QT_END_NAMESPACE
