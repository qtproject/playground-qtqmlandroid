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

#include "qnativeandroidadapterview_p.h"
#include "qnativeandroidadapterview_p_p.h"
#include "qnativeandroidbaseadapter_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidAdapterView::QNativeAndroidAdapterView(QNativeAndroidContext *context)
    : QNativeAndroidViewGroup(*(new QNativeAndroidAdapterViewPrivate), context)
{
}

QNativeAndroidBaseAdapter *QNativeAndroidAdapterView::adapter() const
{
    Q_D(const QNativeAndroidAdapterView);
    return d->adapter;
}

void QNativeAndroidAdapterView::setAdapter(QNativeAndroidBaseAdapter *adapter)
{
    Q_D(QNativeAndroidAdapterView);
    if (d->adapter != adapter) {
        if (d->adapter) {
            d->adapter->setContext(0);
            disconnect(d->adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAdapterView::updateAdapter);
            d->adapter->destruct();
        }
        d->adapter = adapter;
        if (d->adapter) {
            d->adapter->setContext(context());
            connect(d->adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidAdapterView::updateAdapter);
            if (isValid())
                d->adapter->construct();
        }
        emit adapterChanged();
    }
}

void QNativeAndroidAdapterView::setSelection(int position)
{
    QtNativeAndroid::callIntMethod(instance(), "setSelection", position);
}

QAndroidJniObject QNativeAndroidAdapterView::onCreate()
{
    return QAndroidJniObject("android/widget/AdapterView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidAdapterView::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidAdapterView);
    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeAdapterViewListener",
                                   "(Landroid/widget/AdapterView;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    QNativeAndroidViewGroup::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidAdapterView::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onItemClick", "(JI)V", reinterpret_cast<void *>(onItemClick)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidAdapterView::onItemClick(JNIEnv *env, jobject object, jlong instance, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidAdapterView *view = reinterpret_cast<QNativeAndroidAdapterView *>(instance);
    if (view)
        QMetaObject::invokeMethod(view, "click", Qt::QueuedConnection, Q_ARG(int, position));
}

void QNativeAndroidAdapterView::objectChange(ObjectChange change)
{
    QNativeAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QNativeAndroidAdapterView::updateAdapter()
{
    Q_D(QNativeAndroidAdapterView);
    if (!isValid())
        return;

    QAndroidJniObject adapter;
    if (d->adapter)
        adapter = d->adapter->instance();

    QAndroidJniObject view = instance();
    QtNativeAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/widget/Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
