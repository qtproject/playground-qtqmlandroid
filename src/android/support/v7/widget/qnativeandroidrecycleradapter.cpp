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

#include "qnativeandroidrecycleradapter_p.h"
#include "qnativeandroidcontextual_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidview_p.h"
#include <QtQml/qqmlcomponent.h>
#include <QtQml/qqmlcontext.h>

QT_BEGIN_NAMESPACE

class QNativeAndroidRecyclerAdapterPrivate : public QNativeAndroidContextualPrivate
{
public:
    int count = 0;
    QQmlComponent *delegate = nullptr;
    QList<QAndroidJniObject> holders;
};

QNativeAndroidRecyclerAdapter::QNativeAndroidRecyclerAdapter(QObject *parent)
    : QNativeAndroidContextual(*(new QNativeAndroidRecyclerAdapterPrivate), parent)
{
}

int QNativeAndroidRecyclerAdapter::count() const
{
    Q_D(const QNativeAndroidRecyclerAdapter);
    return d->count;
}

void QNativeAndroidRecyclerAdapter::setCount(int count)
{
    Q_D(QNativeAndroidRecyclerAdapter);
    if (d->count != count) {
        d->count = count;
        QtNativeAndroid::callIntMethod(instance(), "setItemCount", count);
        emit countChanged();
    }
}

QQmlComponent *QNativeAndroidRecyclerAdapter::delegate() const
{
    Q_D(const QNativeAndroidRecyclerAdapter);
    return d->delegate;
}

void QNativeAndroidRecyclerAdapter::setDelegate(QQmlComponent *delegate)
{
    Q_D(QNativeAndroidRecyclerAdapter);
    if (d->delegate != delegate) {
        d->delegate = delegate;
        QtNativeAndroid::callVoidMethod(instance(), "notifyDataSetChanged");
        emit delegateChanged();
    }
}

QAndroidJniObject QNativeAndroidRecyclerAdapter::onCreate()
{
    Q_D(QNativeAndroidRecyclerAdapter);
    return QAndroidJniObject("org/qtproject/qt5/android/bindings/support/v7/widget/QtNativeRecyclerAdapter",
                             "(IJ)V",
                             d->count,
                             reinterpret_cast<jlong>(this));
}

void QNativeAndroidRecyclerAdapter::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidRecyclerAdapter);
    QNativeAndroidContextual::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }

    if (d->count > 0)
        instance.callMethod<void>("setItemCount", "(I)V", d->count);
}

void QNativeAndroidRecyclerAdapter::onRegisterNativeMethods(jobject adapter)
{
    JNINativeMethod methods[] {{"onCreateViewHolder", "(JLandroid/view/ViewGroup;I)Lorg/qtproject/qt5/android/bindings/support/v7/widget/QtNativeRecyclerAdapter$ViewHolder;", reinterpret_cast<void *>(onCreateViewHolder)},
                               {"onBindViewHolder", "(JLorg/qtproject/qt5/android/bindings/support/v7/widget/QtNativeRecyclerAdapter$ViewHolder;I)V", reinterpret_cast<void *>(onBindViewHolder)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(adapter);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

jobject QNativeAndroidRecyclerAdapter::onCreateViewHolder(JNIEnv *env, jobject object, jlong instance, jobject parent, jint viewType)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    Q_UNUSED(parent);
    Q_UNUSED(viewType);
    QNativeAndroidRecyclerAdapter *adapter = reinterpret_cast<QNativeAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        QNativeAndroidView *item = nullptr;
        QMetaObject::invokeMethod(adapter, "createItem", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QNativeAndroidView *, item));
        item->construct();
        adapter->d_func()->holders += QAndroidJniObject("org/qtproject/qt5/android/bindings/support/v7/widget/QtNativeRecyclerAdapter$ViewHolder",
                                                "(Landroid/view/View;J)V",
                                                item->instance().object(),
                                                reinterpret_cast<jlong>(item));
        return adapter->d_func()->holders.last().object();
    }
    return 0;
}

void QNativeAndroidRecyclerAdapter::onBindViewHolder(JNIEnv *env, jobject object, jlong instance, jobject holder, jint position)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidRecyclerAdapter *adapter = reinterpret_cast<QNativeAndroidRecyclerAdapter *>(instance);
    if (adapter) {
        jlong vi = QAndroidJniObject(holder).callMethod<jlong>("getInstance");
        QNativeAndroidView *item = reinterpret_cast<QNativeAndroidView *>(vi);
        if (item)
            QMetaObject::invokeMethod(adapter, "setItemPosition", Qt::BlockingQueuedConnection, Q_ARG(QNativeAndroidView *, item), Q_ARG(int, position));
    }
}

QNativeAndroidView *QNativeAndroidRecyclerAdapter::createItem()
{
    Q_D(QNativeAndroidRecyclerAdapter);
    QNativeAndroidView *item = nullptr;
    if (d->delegate) {
        QQmlContext *creationContext = d->delegate->creationContext();
        QQmlContext *context = new QQmlContext(creationContext ? creationContext : qmlContext(this));
        QObject *object = d->delegate->beginCreate(context);
        if (object) {
            context->setParent(object);
            item = qobject_cast<QNativeAndroidView *>(object);
            if (!item)
                delete object;
        } else {
            delete context;
        }
    } else {
        item = new QNativeAndroidView;
    }
    if (item) {
        item->setContext(context());
        item->setParentView(qobject_cast<QNativeAndroidView *>(parent())); // TODO
        setItemPosition(item, -1);
    }
    if (d->delegate)
        d->delegate->completeCreate();
    return item;
}

void QNativeAndroidRecyclerAdapter::setItemPosition(QNativeAndroidView *item, int position)
{
    QQmlContext *context = qmlContext(item);
    if (context)
        context = context->parentContext();
    if (context)
        context->setContextProperty(QStringLiteral("position"), position);
}

QT_END_NAMESPACE
