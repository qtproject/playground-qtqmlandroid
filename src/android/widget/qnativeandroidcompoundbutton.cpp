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

#include "qnativeandroidcompoundbutton_p.h"
#include "qnativeandroidcompoundbutton_p_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidCompoundButton::QNativeAndroidCompoundButton(QNativeAndroidContext *context)
    : QNativeAndroidButton(*(new QNativeAndroidCompoundButtonPrivate), context)
{
}

QNativeAndroidCompoundButton::QNativeAndroidCompoundButton(QNativeAndroidCompoundButtonPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidButton(dd, context)
{
}

bool QNativeAndroidCompoundButton::isChecked() const
{
    Q_D(const QNativeAndroidCompoundButton);
    return d->checked;
}

void QNativeAndroidCompoundButton::setChecked(bool checked)
{
    if (updateChecked(checked))
        QtNativeAndroid::callBoolMethod(instance(), "setChecked", checked);
}

bool QNativeAndroidCompoundButton::updateChecked(bool arg)
{
    Q_D(QNativeAndroidCompoundButton);
    if (arg != isChecked()) {
        d->checked = arg;
        emit checkedChanged();
        return true;
    }
    return false;
}

void QNativeAndroidCompoundButton::toggle()
{
    QtNativeAndroid::callVoidMethod(instance(), "toggle");
}

QAndroidJniObject QNativeAndroidCompoundButton::onCreate()
{
    return QAndroidJniObject("android/widget/CompoundButton",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidCompoundButton::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidCompoundButton);
    QNativeAndroidButton::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeCompoundButtonListener",
                                   "(Landroid/widget/CompoundButton;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setChecked", "(Z)V", d->checked);
}

void QNativeAndroidCompoundButton::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JZ)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidCompoundButton::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jboolean isChecked)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidCompoundButton *button = reinterpret_cast<QNativeAndroidCompoundButton *>(instance);
    if (button)
        QMetaObject::invokeMethod(button, "updateChecked", Qt::QueuedConnection, Q_ARG(bool, isChecked));
}

QT_END_NAMESPACE
