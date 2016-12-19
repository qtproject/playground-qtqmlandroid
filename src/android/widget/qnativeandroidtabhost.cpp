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

#include "qnativeandroidtabhost_p.h"
#include "qnativeandroidframelayout_p_p.h"
#include "qnativeandroidtabspec_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidTabHostPrivate : public QNativeAndroidFrameLayoutPrivate
{
public:
    QAndroidJniObject listener;
};

QNativeAndroidTabHost::QNativeAndroidTabHost(QNativeAndroidContext *context)
    : QNativeAndroidFrameLayout(*(new QNativeAndroidTabHostPrivate), context)
{
}

QAndroidJniObject QNativeAndroidTabHost::onCreate()
{
    return QAndroidJniObject("android/widget/TabHost",
                             "(Landroid/content/Context;Landroid/util/AttributeSet;)V",
                             ctx().object(), 0);
}

void QNativeAndroidTabHost::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidTabHost);
    QNativeAndroidFrameLayout::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeTabHostListener",
                                   "(Landroid/widget/TabHost;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setup");

    int index = 0;
    QList<QNativeAndroidTabSpec *> tabs = findChildren<QNativeAndroidTabSpec *>();
    foreach (QNativeAndroidTabSpec *tab, tabs)
        tab->setup(instance, index++);
}

void QNativeAndroidTabHost::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onTabChanged", "(JLjava/lang/String;)V", reinterpret_cast<void *>(onTabChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidTabHost::onTabChanged(JNIEnv *env, jobject object, jlong instance, jstring tabId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidTabHost *host = reinterpret_cast<QNativeAndroidTabHost *>(instance);
    if (host)
        QMetaObject::invokeMethod(host, "tabChanged", Qt::QueuedConnection, Q_ARG(QString, QAndroidJniObject(tabId).toString()));
}

QT_END_NAMESPACE
