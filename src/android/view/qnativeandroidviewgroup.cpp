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

#include "qnativeandroidviewgroup_p.h"
#include "qnativeandroidviewgroup_p_p.h"
#include "qnativeandroidlayoutparams_p.h"
#include "qtnativeandroidfunctions_p.h"
#include "qnativeandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidViewGroup::QNativeAndroidViewGroup(QNativeAndroidContext *context)
    : QNativeAndroidView(*(new QNativeAndroidViewGroupPrivate), context)
{
}

QNativeAndroidViewGroup::QNativeAndroidViewGroup(QNativeAndroidViewGroupPrivate &dd, QNativeAndroidContext *context)
    : QNativeAndroidView(dd, context)
{
}

QNativeAndroidLayoutParams *QNativeAndroidViewGroup::qmlAttachedProperties(QObject *object)
{
    QNativeAndroidView *view = qobject_cast<QNativeAndroidView*>(object);
    if (view)
        return new QNativeAndroidLayoutParams(view);
    return 0;
}

QAndroidJniObject QNativeAndroidViewGroup::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidViewGroup::onInflate(QAndroidJniObject &instance)
{
    QNativeAndroidView::onInflate(instance);

    foreach (QNativeAndroidView *child, childViews())
        instance.callMethod<void>("addView", "(Landroid/view/View;)V", child->instance().object());
}

void QNativeAndroidViewGroup::viewChange(ViewChange change, const ViewChangeData &data)
{
    Q_UNUSED(data);
    QAndroidJniObject group = instance();
    switch (change) {
    case ViewChildAddedChange: // data.view
        if (group.isValid()) {
//            QtNativeAndroid::callFunction([=]() {
//                QAndroidJniObject child = data.view->onCreate();
//                data.view->onInflate(child);
//                data.view->setInstance(child);
//                group.callMethod<void>("addView", "(Landroid/view/View;)V", child.object());
//            });
        }
        break;
    case ViewChildRemovedChange: // data.view
        if (group.isValid()) {
//            QAndroidJniObject child = data.view->instance();
//            QtNativeAndroid::callFunction([=]() {
//                group.callMethod<void>("removeView", "(Landroid/view/View;)V", child.object());
//            });
//            data.view->setInstance(QAndroidJniObject());
        }
        break;
    default:
        break;
    }
}

QT_END_NAMESPACE
