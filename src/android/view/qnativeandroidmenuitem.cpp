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
#include "qnativeandroidcontextual_p_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidcontext_p.h"
#include "qnativeandroidview_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidMenuItemPrivate : public QNativeAndroidContextualPrivate
{
public:
    QString title;
    bool enabled = true;
    bool visible = true;
    bool checkable = false;
    bool checked = false;
    int showAs = 0; // TODO: SHOW_AS_ACTION_NEVER
    QNativeAndroidView *actionView = nullptr;
};

QNativeAndroidMenuItem::QNativeAndroidMenuItem(QObject *parent)
    : QNativeAndroidContextual(*(new QNativeAndroidMenuItemPrivate), parent)
{
}

QString QNativeAndroidMenuItem::title() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->title;
}

void QNativeAndroidMenuItem::setTitle(const QString &title)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->title != title) {
        d->title = title;
        QtNativeAndroid::callTextMethod(instance(), "setTitle", title);
        emit titleChanged();
    }
}

bool QNativeAndroidMenuItem::isEnabled() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->enabled;
}

void QNativeAndroidMenuItem::setEnabled(bool enabled)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->enabled != enabled) {
        d->enabled = enabled;
        QtNativeAndroid::callBoolMethod(instance(), "setEnabled", enabled);
        emit enabledChanged();
    }
}

bool QNativeAndroidMenuItem::isVisible() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->visible;
}

void QNativeAndroidMenuItem::setVisible(bool visible)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->visible != visible) {
        d->visible = visible;
        QtNativeAndroid::callBoolMethod(instance(), "setVisible", visible);
        if (isValid() && context())
            QMetaObject::invokeMethod(context(), "invalidateOptionsMenu");
        emit visibleChanged();
    }
}

bool QNativeAndroidMenuItem::isCheckable() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->checkable;
}

void QNativeAndroidMenuItem::setCheckable(bool checkable)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->checkable != checkable) {
        d->checkable = checkable;
        QtNativeAndroid::callBoolMethod(instance(), "setCheckable", checkable);
        emit checkableChanged();
    }
}

bool QNativeAndroidMenuItem::isChecked() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->checked;
}

void QNativeAndroidMenuItem::setChecked(bool checked)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->checked != checked) {
        d->checked = checked;
        QtNativeAndroid::callBoolMethod(instance(), "setChecked", checked);
        emit checkedChanged();
    }
}

int QNativeAndroidMenuItem::showAs() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->showAs;
}

void QNativeAndroidMenuItem::setShowAs(int showAs)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->showAs != showAs) {
        d->showAs = showAs;
        QtNativeAndroid::callIntMethod(instance(), "setShowAs", showAs);
        emit showAsChanged();
    }
}

QNativeAndroidView *QNativeAndroidMenuItem::actionView() const
{
    Q_D(const QNativeAndroidMenuItem);
    return d->actionView;
}

void QNativeAndroidMenuItem::setActionView(QNativeAndroidView *view)
{
    Q_D(QNativeAndroidMenuItem);
    if (d->actionView != view) {
        if (d->actionView) {
            disconnect(d->actionView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidMenuItem::updateActionView);
            d->actionView->destruct();
        }
        d->actionView = view;
        if (d->actionView) {
            connect(d->actionView, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidMenuItem::updateActionView);
            if (isValid())
                d->actionView->construct();
        }
        emit actionViewChanged();
    }
}

QAndroidJniObject QNativeAndroidMenuItem::onCreate()
{
    return QAndroidJniObject("org/qtproject/qt5/android/bindings/view/QtNativeMenuItem",
                             "(J)V",
                             reinterpret_cast<jlong>(this));
}

void QNativeAndroidMenuItem::onInflate(QAndroidJniObject &instance)
{
    Q_D(QNativeAndroidMenuItem);
    instance.callMethod<void>("setTitle", "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(d->title).object());
    instance.callMethod<void>("setEnabled", "(Z)V", d->enabled);
    instance.callMethod<void>("setVisible", "(Z)V", d->visible);
    instance.callMethod<void>("setCheckable", "(Z)V", d->checkable);
    instance.callMethod<void>("setChecked", "(Z)V", d->enabled);
    instance.callMethod<void>("setShowAs", "(I)V", d->showAs);

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
    Q_D(QNativeAndroidMenuItem);
    if (!isValid() || !d->actionView)
        return;

    QAndroidJniObject item = instance();
    QAndroidJniObject view = d->actionView->instance();
    QtNativeAndroid::callFunction([=]() {
        item.callMethod<void>("setActionView", "(Landroid/view/View;)V", view.object());
    });
}

QT_END_NAMESPACE
