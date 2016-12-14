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

#include "qnativeandroidratingbar_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidRatingBar::QNativeAndroidRatingBar(QNativeAndroidView *parent) :
    QNativeAndroidAbsSeekBar(parent), m_rating(0.0)
{
}

qreal QNativeAndroidRatingBar::rating() const
{
    return m_rating;
}

void QNativeAndroidRatingBar::setRating(qreal rating)
{
    if (updateRating(rating))
        QtQmlAndroid::callRealMethod(instance(), "setRating", rating);
}

bool QNativeAndroidRatingBar::updateRating(qreal rating)
{
    if (!qFuzzyCompare(m_rating, rating)) {
        m_rating = rating;
        emit ratingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QNativeAndroidRatingBar::onCreate()
{
    return QAndroidJniObject("android/widget/RatingBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidRatingBar::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidAbsSeekBar::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QmlRatingBarListener",
                                   "(Landroid/widget/RatingBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setRating", "(F)V", m_rating);
}

void QNativeAndroidRatingBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRatingChanged", "(JFZ)V", reinterpret_cast<void *>(onRatingChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QNativeAndroidRatingBar::onRatingChanged(JNIEnv *env, jobject object, jlong instance, jfloat rating, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QNativeAndroidRatingBar *bar = reinterpret_cast<QNativeAndroidRatingBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateRating", Qt::QueuedConnection, Q_ARG(qreal, rating));
}

QT_END_NAMESPACE