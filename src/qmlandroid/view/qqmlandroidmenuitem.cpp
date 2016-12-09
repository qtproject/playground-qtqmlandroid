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

#include "qqmlandroidmenuitem_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidcontext_p.h"
#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidMenuItem::QQmlAndroidMenuItem(QObject *parent) :
    QQmlAndroidContextual(parent), m_enabled(true), m_visible(true),
    m_checkable(false), m_checked(false),
    m_showAs(0), // TODO: SHOW_AS_ACTION_NEVER
    m_actionView(0)
{
}

QString QQmlAndroidMenuItem::title() const
{
    return m_title;
}

void QQmlAndroidMenuItem::setTitle(const QString &title)
{
    if (m_title != title) {
        m_title = title;
        QtQmlAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

bool QQmlAndroidMenuItem::isEnabled() const
{
    return m_enabled;
}

void QQmlAndroidMenuItem::setEnabled(bool enabled)
{
    if (m_enabled != enabled) {
        m_enabled = enabled;
        QtQmlAndroid::callBoolMethod(instance(), "setEnabled", enabled);
        emit enabledChanged();
    }
}

bool QQmlAndroidMenuItem::isVisible() const
{
    return m_visible;
}

void QQmlAndroidMenuItem::setVisible(bool visible)
{
    if (m_visible != visible) {
        m_visible = visible;
        QtQmlAndroid::callBoolMethod(instance(), "setVisible", visible);
        if (isValid() && context())
            QMetaObject::invokeMethod(context(), "invalidateOptionsMenu");
        emit visibleChanged();
    }
}

bool QQmlAndroidMenuItem::isCheckable() const
{
    return m_checkable;
}

void QQmlAndroidMenuItem::setCheckable(bool checkable)
{
    if (m_checkable != checkable) {
        m_checkable = checkable;
        QtQmlAndroid::callBoolMethod(instance(), "setCheckable", checkable);
        emit checkableChanged();
    }
}

bool QQmlAndroidMenuItem::isChecked() const
{
    return m_checked;
}

void QQmlAndroidMenuItem::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = checked;
        QtQmlAndroid::callBoolMethod(instance(), "setChecked", checked);
        emit checkedChanged();
    }
}

int QQmlAndroidMenuItem::showAs() const
{
    return m_showAs;
}

void QQmlAndroidMenuItem::setShowAs(int showAs)
{
    if (m_showAs != showAs) {
        m_showAs = showAs;
        QtQmlAndroid::callIntMethod(instance(), "setShowAs", showAs);
        emit showAsChanged();
    }
}

QQmlAndroidView *QQmlAndroidMenuItem::actionView() const
{
    return m_actionView;
}

void QQmlAndroidMenuItem::setActionView(QQmlAndroidView *view)
{
    if (m_actionView != view) {
        if (m_actionView) {
            disconnect(m_actionView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidMenuItem::updateActionView);
            m_actionView->destruct();
        }
        m_actionView = view;
        if (m_actionView) {
            connect(m_actionView, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidMenuItem::updateActionView);
            if (isValid())
                m_actionView->construct();
        }
        emit actionViewChanged();
    }
}

QAndroidJniObject QQmlAndroidMenuItem::onCreate()
{
    return QAndroidJniObject("qt/android/view/QmlMenuItem",
                             "(J)V",
                             reinterpret_cast<jlong>(this));
}

void QQmlAndroidMenuItem::onInflate(QAndroidJniObject &instance)
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

void QQmlAndroidMenuItem::onRegisterNativeMethods(jobject item)
{
    JNINativeMethod methods[] {{"onClick", "(J)Z", reinterpret_cast<void *>(onClick)},
                               {"onMenuItemActionCollapse", "(J)Z", reinterpret_cast<void *>(onMenuItemActionCollapse)},
                               {"onMenuItemActionExpand", "(J)Z", reinterpret_cast<void *>(onMenuItemActionExpand)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(item);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

bool QQmlAndroidMenuItem::onClick(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidMenuItem *item = reinterpret_cast<QQmlAndroidMenuItem *>(instance);
    if (item) {
        QMetaObject::invokeMethod(item, "click", Qt::QueuedConnection);
        return true;
    }
    return false;
}

bool QQmlAndroidMenuItem::onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidMenuItem *item = reinterpret_cast<QQmlAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;
}

bool QQmlAndroidMenuItem::onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidMenuItem *item = reinterpret_cast<QQmlAndroidMenuItem *>(instance);
    if (item) {
        // TODO
        return true;
    }
    return false;

}

void QQmlAndroidMenuItem::objectChange(ObjectChange change)
{
    QQmlAndroidContextual::objectChange(change);
    if (change == InstanceChange)
        updateActionView();
}

void QQmlAndroidMenuItem::updateActionView()
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
