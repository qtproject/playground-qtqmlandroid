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

#include "qnativeandroidradiogroup_p.h"
#include "qnativeandroidlinearlayout_p_p.h"
#include "qnativeandroidradiobutton_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidRadioGroupPrivate : public QNativeAndroidLinearLayoutPrivate
{
public:
    QAndroidJniObject listener;
    QNativeAndroidRadioButton* checkedButton = nullptr;
};

QNativeAndroidRadioGroup::QNativeAndroidRadioGroup(QNativeAndroidContext *context)
    : QNativeAndroidLinearLayout(*(new QNativeAndroidRadioGroupPrivate), context)
{
}

QNativeAndroidRadioButton *QNativeAndroidRadioGroup::checkedButton() const
{
    Q_D(const QNativeAndroidRadioGroup);
    return d->checkedButton;
}

void QNativeAndroidRadioGroup::setCheckedButton(QNativeAndroidRadioButton *button)
{
    if (updateCheckedButton(button))
        QtNativeAndroid::callIntMethod(instance(), "check", button ? button->identifier() : -1);
}

void QNativeAndroidRadioGroup::clearCheck()
{
    QtNativeAndroid::callVoidMethod(instance(), "clearCheck");
}

QAndroidJniObject QNativeAndroidRadioGroup::onCreate()
{
    return QAndroidJniObject("android/widget/RadioGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidRadioGroup::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidRadioGroup);
    QNativeAndroidLinearLayout::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeRadioGroupListener",
                                   "(Landroid/widget/RadioGroup;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }

    int checkedId = instance.callMethod<int>("getCheckedRadioButtonId", "()I");
    QMetaObject::invokeMethod(this, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QNativeAndroidRadioGroup::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onCheckedChanged", "(JI)V", reinterpret_cast<void *>(onCheckedChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidRadioGroup::onCheckedChanged(JNIEnv *env, jobject object, jlong instance, jint checkedId)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidRadioGroup *group = reinterpret_cast<QNativeAndroidRadioGroup *>(instance);
    if (group)
        QMetaObject::invokeMethod(group, "updateCheckedButtonId", Qt::QueuedConnection, Q_ARG(int, checkedId));
}

void QNativeAndroidRadioGroup::updateCheckedButtonId(int checkedId)
{
    foreach (QObject *child, QObject::children()) {
        QNativeAndroidRadioButton *button = qobject_cast<QNativeAndroidRadioButton *>(child);
        if (button && button->identifier() == checkedId) {
            updateCheckedButton(button);
            return;
        }
    }
    updateCheckedButton(0);
}

bool QNativeAndroidRadioGroup::updateCheckedButton(QNativeAndroidRadioButton *button)
{
    Q_D(QNativeAndroidRadioGroup);
    if (d->checkedButton != button) {
        d->checkedButton = button;
        emit checkedButtonChanged();
        return true;
    }
    return false;
}

QT_END_NAMESPACE
