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

#include "qnativeandroidseekbar_p.h"
#include "qnativeandroidabsseekbar_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidSeekBarPrivate : public QNativeAndroidAbsSeekBarPrivate
{
public:
    QAndroidJniObject listener;
};

QNativeAndroidSeekBar::QNativeAndroidSeekBar(QNativeAndroidContext *context)
    : QNativeAndroidAbsSeekBar(*(new QNativeAndroidSeekBarPrivate), context)
{
}

QAndroidJniObject QNativeAndroidSeekBar::onCreate()
{
    return QAndroidJniObject("android/widget/SeekBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidSeekBar::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidSeekBar);
    QNativeAndroidAbsSeekBar::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeSeekBarListener",
                                   "(Landroid/widget/SeekBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidSeekBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onProgressChanged", "(JIZ)V", reinterpret_cast<void *>(onProgressChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidSeekBar::onProgressChanged(JNIEnv *env, jobject object, jlong instance, jint progress, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidSeekBar *bar = reinterpret_cast<QNativeAndroidSeekBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateProgress", Qt::QueuedConnection, Q_ARG(int, progress));
}

QT_END_NAMESPACE
