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

#include "qtqmlandroidanimationmodule_p.h"

#include "qqmlandroidacceleratedecelerateinterpolator_p.h"
#include "qqmlandroidaccelerateinterpolator_p.h"
#include "qqmlandroidalphaanimation_p.h"
#include "qqmlandroidanimation_p.h"
#include "qqmlandroidanimationset_p.h"
#include "qqmlandroidanticipateinterpolator_p.h"
#include "qqmlandroidanticipateovershootinterpolator_p.h"
#include "qqmlandroidbounceinterpolator_p.h"
#include "qqmlandroidcycleinterpolator_p.h"
#include "qqmlandroiddecelerateinterpolator_p.h"
#include "qqmlandroidlinearinterpolator_p.h"
#include "qqmlandroidovershootinterpolator_p.h"
#include "qqmlandroidpathinterpolator_p.h"
#include "qqmlandroidrotateanimation_p.h"
#include "qqmlandroidscaleanimation_p.h"
#include "qqmlandroidtranslateanimation_p.h"

#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

namespace QtQmlAndroid {

void registerAnimationModule(const char *uri)
{
    qmlRegisterType<QQmlAndroidAccelerateDecelerateInterpolator>(uri, 0, 21, "AccelerateDecelerateInterpolator");
    qmlRegisterType<QQmlAndroidAccelerateInterpolator>(uri, 0, 21, "AccelerateInterpolator");
    qmlRegisterType<QQmlAndroidAlphaAnimation>(uri, 0, 21, "AlphaAnimation");
    qmlRegisterType<QQmlAndroidAnimation>(uri, 0, 21, "Animation");
    qmlRegisterType<QQmlAndroidAnimationSet>(uri, 0, 21, "AnimationSet");
    qmlRegisterType<QQmlAndroidAnticipateInterpolator>(uri, 0, 21, "AnticipateInterpolator");
    qmlRegisterType<QQmlAndroidAnticipateOvershootInterpolator>(uri, 0, 21, "AnticipateOvershootInterpolator");
    qmlRegisterType<QQmlAndroidBounceInterpolator>(uri, 0, 21, "BounceInterpolator");
    qmlRegisterType<QQmlAndroidCycleInterpolator>(uri, 0, 21, "CycleInterpolator");
    qmlRegisterType<QQmlAndroidDecelerateInterpolator>(uri, 0, 21, "DecelerateInterpolator");
    qmlRegisterUncreatableType<QQmlAndroidInterpolator>(uri, 0, 21, "Interpolator", QStringLiteral("Interpolator is abstract"));
    qmlRegisterType<QQmlAndroidLinearInterpolator>(uri, 0, 21, "LinearInterpolator");
    qmlRegisterType<QQmlAndroidOvershootInterpolator>(uri, 0, 21, "OvershootInterpolator");
    qmlRegisterType<QQmlAndroidPathInterpolator>(uri, 0, 21, "PathInterpolator");
    qmlRegisterType<QQmlAndroidRotateAnimation>(uri, 0, 21, "RotateAnimation");
    qmlRegisterType<QQmlAndroidScaleAnimation>(uri, 0, 21, "ScaleAnimation");
    qmlRegisterType<QQmlAndroidTranslateAnimation>(uri, 0, 21, "TranslateAnimation");
}

}

QT_END_NAMESPACE
