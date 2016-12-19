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
#include "qnativeandroidabsseekbar_p_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidRatingBarPrivate : public QNativeAndroidAbsSeekBarPrivate
{
public:
    qreal rating = 0.0;
    QAndroidJniObject listener;
};

QNativeAndroidRatingBar::QNativeAndroidRatingBar(QNativeAndroidContext *context)
    : QNativeAndroidAbsSeekBar(*(new QNativeAndroidRatingBarPrivate), context)
{
}

qreal QNativeAndroidRatingBar::rating() const
{
    Q_D(const QNativeAndroidRatingBar);
    return d->rating;
}

void QNativeAndroidRatingBar::setRating(qreal rating)
{
    if (updateRating(rating))
        QtNativeAndroid::callRealMethod(instance(), "setRating", rating);
}

bool QNativeAndroidRatingBar::updateRating(qreal rating)
{
    Q_D(QNativeAndroidRatingBar);
    if (!qFuzzyCompare(d->rating, rating)) {
        d->rating = rating;
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
    Q_D(QNativeAndroidRatingBar);
    QNativeAndroidAbsSeekBar::onInflate(instance);

    d->listener = QAndroidJniObject("org/qtproject/qt5/android/bindings/widget/QtNativeRatingBarListener",
                                   "(Landroid/widget/RatingBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(d->listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setRating", "(F)V", d->rating);
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
