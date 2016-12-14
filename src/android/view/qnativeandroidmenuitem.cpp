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

#include "qnativeandroidmenuitem_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qnativeandroidcontext_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidMenuItem::QNativeAndroidMenuItem(QObject *parent) :
    QNativeAndroidContextual(parent), m_enabled(true), m_visible(true),
    m_checkable(false), m_checked(false),
    m_showAs(0), // TODO: SHOW_AS_ACTION_NEVER
    m_actionView(0)
{
}

QString QNativeAndroidMenuItem::title() const
{
    return m_title;
}

void QNativeAndroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

bool QNativeAndroidMenuItem::isEnabled() const
{
    return m_enabled;
}

void QNativeAndroidMenuItem::setEnabled(bool enabled)
{
    if (m_enabled != enabled) {
        m_enabled = enabled;
        QtQmlAndroid::callBoolMethod(instance(), "setEnabled", enabled);
        emit enabledChanged();
    }
}

bool QNativeAndroidMenuItem::isVisible() const
{
    return m_visible;
}

void QNativeAndroidMenuItem::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        QtQmlAndroid::callBoolMethod(instance(), "setVisible", visible);
        if (isValid() && context())
            QMetaObject::invokeMethod(context(), "invalidateOptionsMenu");
        emit visibleChanged();
    }
}

bool QNativeAndroidMenuItem::isCheckable() const
{
    return m_checkable;
}

void QNativeAndroidMenuItem::setCheckable(bool checkable)
{
    if (m_checkable != checkable) {
        m_checkable = checkable;
        QtQmlAndroid::callBoolMethod(instance(), "setCheckable", checkable);
        emit checkableChanged();
    }
}

bool QNativeAndroidMenuItem::isChecked() const
{
    return m_checked;
}

void QNativeAndroidMenuItem::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        QtQmlAndroid::callBoolMethod(instance(), "setChecked", checked);
        emit checkedChanged();
    }
}

int QNativeAndroidMenuItem::showAs() const
{
    return m_showAs;
}

void QNativeAndroidMenuItem::setShowAs(int showAs)
{
    if (m_showAs != showAs) {
        m_showAs = showAs;
        QtQmlAndroid::callIntMethod(instance(), "setShowAs", showAs);
        emit showAsChanged();
    }
}

QNativeAndroidView *QNativeAndroidMenuItem::actionView() const
{
    return m_actionView;
}

void QNativeAndroidMenuItem::setActionView(QNativeAndroidView *view)
{
    if (m_actionView != view) {
        if (m_actionView) {
            disconnect(m_actionView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidMenuItem::updateActionView);
            m_actionView->destruct();
        }
        m_actionView = view;
        if (m_actionView) {
            connect(m_actionView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidMenuItem::updateActionView);
            if (isValid())
                m_actionView->construct();
        }
        emit actionViewChanged();
    }
}

QAndroidJniObject QNativeAndroidMenuItem::onCreate()
{
    return QAndroidJniObject("qt/android/view/QmlMenuItem",
                             "(J)V",
                             reinterpret_cast<jlong>(this));
}

void QNativeAndroidMenuItem::onInflate(QAndroidJniObject &instance)
{
    instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(m_title).object());
    instance.callMethod<void>("setEnabled", "(Z)V", m_enabled);
    instance.callMethod<void>("setVisible", "(Z)V", m_visible);
    instance.callMethod<void>("setCheckable", "(Z)V", m_checkable);
    instance.callMethod<void>("setChecked", "(Z)V", m_enabled);
    instance.callMethod<void>("setShowAs", "(I)V", m_showAs);

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(instance.object());
        nativeMethodsRegistered = true;
    }
}

void QNativeAndroidMenuItem::onRegisterNativeMethods(jobject item)
{
    JNINativeMethod methods[] {{"onClick", "(J)Z", reinterpret_cast<void *>(onClick)},
                               {"onMenuItemActionCollapse", "(J)Z", reinterpret_cast<void *>(onMenuItemActionCollapse)},
                               {"onMenuItemActionExpand", "(J)Z", reinterpret_cast<void *>(onMenuItemActionExpand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(item);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

bool QNativeAndroidMenuItem::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidMenuItem *item = reinterpret_cast<QNativeAndroidMenuItem *>(instance);
    if (item) {
        QMetaObject::invokeMethod(item, "click", Qt::QueuedConnection);
        return true;
    }
    return false;
}

bool QNativeAndroidMenuItem::onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidMenuItem *item = reinterpret_cast<QNativeAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;
}

bool QNativeAndroidMenuItem::onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidMenuItem *item = reinterpret_cast<QNativeAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;

}

void QNativeAndroidMenuItem::objectChange(ObjectChange change)
{
    QNativeAndroidContextual::objectChange(change);
    if (change == InstanceChange)
        updateActionView();
}

void QNativeAndroidMenuItem::updateActionView()
{
    if (!isValid() || !m_actionView)
        return;

    QAndroidJniObject item = instance();
    QAndroidJniObject view = m_actionView->instance();
    QtQmlAndroid::callFunction([=]() {
        item.callMethod<void>("setActionView", "(Landroid/view/View;)V", view.object());
    });
}

QT_END_NAMESPACE
