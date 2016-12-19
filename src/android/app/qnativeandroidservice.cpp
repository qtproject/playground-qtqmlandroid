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

#include "qnativeandroidservice_p.h"
#include "qnativeandroidcontextwrapper_p_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidServicePrivate : public QNativeAndroidContextWrapperPrivate
{
public:
    bool sticky = true;
};

QNativeAndroidService::QNativeAndroidService(QObject *parent)
    : QNativeAndroidContextWrapper(*(new QNativeAndroidServicePrivate), nullptr, parent)
{
}

bool QNativeAndroidService::isSticky() const
{
    Q_D(const QNativeAndroidService);
    return d->sticky;
}

void QNativeAndroidService::setSticky(bool sticky)
{
    Q_D(QNativeAndroidService);
    if (d->sticky != sticky) {
        d->sticky = sticky;
        emit stickyChanged();
    }
}

void QNativeAndroidService::start()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject cls = service.callObjectMethod("getClass", "()Ljava/lang/Class;");
        QAndroidJniObject intent = QAndroidJniObject("android/content/Intent",
                                                     "(Landroid/content/Context;Ljava/lang/Class;)V",
                                                     context.object(),
                                                     cls.object());
        intent.callObjectMethod("putExtra",
                                "(Ljava/lang/String;J)Landroid/content/Intent;",
                                QAndroidJniObject::fromString(QStringLiteral("QtNativeService")).object(),
                                reinterpret_cast<jlong>(this));
        QAndroidJniObject component = context.callObjectMethod("startService",
                                                               "(Landroid/content/Intent;)Landroid/content/ComponentName;",
                                                               intent.object());
        Q_UNUSED(component);
    });
}

void QNativeAndroidService::stop()
{
    QAndroidJniObject context = ctx();
    QAndroidJniObject service = instance();

    if (!context.isValid() || !service.isValid())
        return; // TODO: warn

    QtNativeAndroid::callFunction([=]() {
        QAndroidJniObject cls = service.callObjectMethod("getClass", "()Ljava/lang/Class;");
        QAndroidJniObject intent = QAndroidJniObject("android/content/Intent",
                                                     "(Landroid/content/Context;Ljava/lang/Class;)V",
                                                     context.object(),
                                                     cls.object());
        intent.callObjectMethod("putExtra",
                                "(Ljava/lang/String;J)Landroid/content/Intent;",
                                QAndroidJniObject::fromString(QStringLiteral("QtNativeService")).object(),
                                reinterpret_cast<jlong>(this));
        context.callMethod<jboolean>("stopService",
                                     "(Landroid/content/Intent;)Z",
                                     intent.object());
    });
}

QAndroidJniObject QNativeAndroidService::onCreate()
{
    return QAndroidJniObject("org/qtproject/qt5/android/bindings/app/QtNativeService");
}

void QNativeAndroidService::onInflate(QAndroidJniObject& instance)
{
    QNativeAndroidContextWrapper::onInflate(instance);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidService::onRegisterNativeMethods(jobject service)
{
    JNINativeMethod methods[] {{"onCreated", "(J)V", reinterpret_cast<void *>(onCreated)},
                               {"onDestroyed", "(J)V", reinterpret_cast<void *>(onDestroyed)},
                               {"onStartCommand", "(JII)Z", reinterpret_cast<void *>(onStartCommand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(service);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidService::onCreated(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    Q_UNUSED(instance);
//    QNativeAndroidService *service = reinterpret_cast<QNativeAndroidService *>(instance);
//    if (service)
//        QMetaObject::invokeMethod(service, "created", Qt::QueuedConnection);
}

void QNativeAndroidService::onDestroyed(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidService *service = reinterpret_cast<QNativeAndroidService *>(instance);
    if (service)
        QMetaObject::invokeMethod(service, "stopped", Qt::QueuedConnection);
}

jboolean QNativeAndroidService::onStartCommand(JNIEnv *env, jobject object, jlong instance, jint flags, jint startId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidService *service = reinterpret_cast<QNativeAndroidService *>(instance);
    bool ret = false;
    if (service) {
        QMetaObject::invokeMethod(service, "startCommand", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, ret), Q_ARG(int, flags), Q_ARG(int, startId));
        QMetaObject::invokeMethod(service, "started", Qt::QueuedConnection);
    }
    return ret;
}

bool QNativeAndroidService::startCommand(int flags, int startId)
{
    Q_D(QNativeAndroidService);
    Q_UNUSED(flags);
    Q_UNUSED(startId);
    return d->sticky;
}

QT_END_NAMESPACE
