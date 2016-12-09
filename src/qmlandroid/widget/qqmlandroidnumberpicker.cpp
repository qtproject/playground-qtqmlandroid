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

#include "qqmlandroidnumberpicker_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidNumberPicker::QQmlAndroidNumberPicker(QQmlAndroidView *parent) :
    QQmlAndroidLinearLayout(parent), m_value(0)
{
}

int QQmlAndroidNumberPicker::value() const
{
    return m_value;
}

void QQmlAndroidNumberPicker::setValue(int value)
{
    if (updateValue(value))
        QtQmlAndroid::callIntMethod(instance(), "setValue", value);
}

bool QQmlAndroidNumberPicker::updateValue(int value)
{
    if (m_value != value) {
        m_value = value;
        emit valueChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QQmlAndroidNumberPicker::onCreate()
{
    return QAndroidJniObject("android/widget/NumberPicker",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidNumberPicker::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidLinearLayout::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QmlNumberPickerListener",
                                   "(Landroid/widget/NumberPicker;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setValue", "(I)V", m_value);
}

void QQmlAndroidNumberPicker::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onValueChange", "(JI)V", reinterpret_cast<void *>(onValueChange)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidNumberPicker::onValueChange(JNIEnv *env, jobject object, jlong instance, jint value)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidNumberPicker *picker = reinterpret_cast<QQmlAndroidNumberPicker *>(instance);
    if (picker)
        QMetaObject::invokeMethod(picker, "updateValue", Qt::QueuedConnection, Q_ARG(int, value));
}

QT_END_NAMESPACE
