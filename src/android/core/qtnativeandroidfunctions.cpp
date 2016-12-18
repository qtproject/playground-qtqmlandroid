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

#include "qtnativeandroidfunctions_p.h"
#include <QtCore/qstring.h>
#include <QtCore/private/qjnihelpers_p.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

namespace QtNativeAndroid {

void callFunction(std::function<void()> method)
{
    QAndroidJniEnvironment env;
    QRunnable *runnable = new QtConcurrent::StoredFunctorCall0<void, decltype(method)>(method);
    QtAndroidPrivate::runOnUiThread(runnable, env);
}

void callTextMethod(const QAndroidJniObject &obj, const char *method, const QString &text)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(text).object());
        });
    }
}

void callRealMethod(const QAndroidJniObject &obj, const char *method, qreal value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(F)V", value);
        });
    }
}

void callIntMethod(const QAndroidJniObject &obj, const char *method, int value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(I)V", value);
        });
    }
}

void callBoolMethod(const QAndroidJniObject &obj, const char *method, bool value)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Z)V", value);
        });
    }
}

void callVoidMethod(const QAndroidJniObject &obj, const char *method)
{
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method);
        });
    }
}

}

QT_END_NAMESPACE
