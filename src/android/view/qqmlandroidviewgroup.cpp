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

#include "qqmlandroidviewgroup_p.h"
#include "qqmlandroidlayoutparams_p.h"
#include "qtqmlandroidfunctions_p.h"
#include "qqmlandroidcontext_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidViewGroup::QQmlAndroidViewGroup(QQmlAndroidView *parent) :
    QQmlAndroidView(parent)
{
}

QQmlAndroidLayoutParams *QQmlAndroidViewGroup::qmlAttachedProperties(QObject *object)
{
    QQmlAndroidView *view = qobject_cast<QQmlAndroidView*>(object);
    if (view)
        return new QQmlAndroidLayoutParams(view);
    return 0;
}

QAndroidJniObject QQmlAndroidViewGroup::onCreate()
{
    return QAndroidJniObject("android/view/ViewGroup",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidViewGroup::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidView::onInflate(instance);

    foreach (QQmlAndroidView *child, childViews())
        instance.callMethod<void>("addView", "(Landroid/view/View;)V", child->instance().object());
}

void QQmlAndroidViewGroup::viewChange(ViewChange change, const ViewChangeData &data)
{
    QAndroidJniObject group = instance();
    switch (change) {
    case ViewChildAddedChange: // data.view
        if (group.isValid()) {
//            QtQmlAndroid::callFunction([=]() {
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
//            QtQmlAndroid::callFunction([=]() {
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
