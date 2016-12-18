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

#include "qnativeandroidanimationset_p.h"
#include "qnativeandroidanimation_p_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidAnimationSetPrivate : public QNativeAndroidAnimationPrivate
{
public:
    bool shareInterpolator = false;
};

QNativeAndroidAnimationSet::QNativeAndroidAnimationSet(QObject *parent)
    : QNativeAndroidAnimation(*(new QNativeAndroidAnimationSetPrivate), parent)
{
}

bool QNativeAndroidAnimationSet::shareInterpolator() const
{
    Q_D(const QNativeAndroidAnimationSet);
    return d->shareInterpolator;
}

void QNativeAndroidAnimationSet::setShareInterpolator(bool share)
{
    Q_D(QNativeAndroidAnimationSet);
    if (d->shareInterpolator != share) {
        d->shareInterpolator = share;
        emit shareInterpolatorChanged();
    }
}

QAndroidJniObject QNativeAndroidAnimationSet::onCreate()
{
    Q_D(QNativeAndroidAnimationSet);
    return QAndroidJniObject("android/view/animation/AnimationSet",
                             "(Z)V",
                             d->shareInterpolator);
}

void QNativeAndroidAnimationSet::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidAnimation::onInflate(instance);

    foreach (QObject *object, children()) {
        QNativeAndroidAnimation *child = qobject_cast<QNativeAndroidAnimation *>(object);
        if (child) {
            QAndroidJniObject animation = child->instance();
            if (animation.isValid())
                instance.callMethod<void>("addAnimation", "(Landroid/view/animation/Animation;)V", animation.object());
        }
    }
}

QT_END_NAMESPACE
