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

#include <QtQml/qqmlextensionplugin.h>
#include <QtQml/qqml.h>

#include <QtQmlAndroid/private/qqmlandroidacceleratedecelerateinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidaccelerateinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidalphaanimation_p.h>
#include <QtQmlAndroid/private/qqmlandroidanimation_p.h>
#include <QtQmlAndroid/private/qqmlandroidanimationset_p.h>
#include <QtQmlAndroid/private/qqmlandroidanticipateinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidanticipateovershootinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidbounceinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidcycleinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroiddecelerateinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidlinearinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidovershootinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidpathinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidrotateanimation_p.h>
#include <QtQmlAndroid/private/qqmlandroidscaleanimation_p.h>
#include <QtQmlAndroid/private/qqmlandroidtranslateanimation_p.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidAnimationPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    void registerTypes(const char *uri) override;
};

void QtQmlAndroidAnimationPlugin::registerTypes(const char *uri)
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

QT_END_NAMESPACE

#include "qtqmlandroidanimationplugin.moc"
