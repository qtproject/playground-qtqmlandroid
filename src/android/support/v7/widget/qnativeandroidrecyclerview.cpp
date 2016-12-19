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

#include "qnativeandroidrecyclerview_p.h"
#include "qnativeandroidviewgroup_p_p.h"
#include "qnativeandroidrecycleradapter_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

class QNativeAndroidRecyclerViewPrivate : public QNativeAndroidViewGroupPrivate
{
public:
    QNativeAndroidRecyclerAdapter *adapter = nullptr;
    QAndroidJniObject layoutManager;
};

QNativeAndroidRecyclerView::QNativeAndroidRecyclerView(QNativeAndroidContext *context)
    : QNativeAndroidViewGroup(*(new QNativeAndroidRecyclerViewPrivate), context)
{
}

QNativeAndroidRecyclerAdapter *QNativeAndroidRecyclerView::adapter() const
{
    Q_D(const QNativeAndroidRecyclerView);
    return d->adapter;
}

void QNativeAndroidRecyclerView::setAdapter(QNativeAndroidRecyclerAdapter *adapter)
{
    Q_D(QNativeAndroidRecyclerView);
    if (d->adapter != adapter) {
        if (d->adapter) {
            d->adapter->setContext(0);
            disconnect(d->adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidRecyclerView::updateAdapter);
            d->adapter->destruct();
        }
        d->adapter = adapter;
        if (d->adapter) {
            d->adapter->setContext(context());
            connect(d->adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidRecyclerView::updateAdapter);
            if (isValid())
                d->adapter->construct();
        }
        emit adapterChanged();
    }}

QAndroidJniObject QNativeAndroidRecyclerView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/RecyclerView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QNativeAndroidRecyclerView::onInflate(QAndroidJniObject& instance)
{
    Q_D(QNativeAndroidRecyclerView);
    d->layoutManager = QAndroidJniObject("android/support/v7/widget/LinearLayoutManager",
                                        "(Landroid/content/Context;)V",
                                        ctx().object());

    instance.callMethod<void>("setLayoutManager",
                              "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                              d->layoutManager.object());

    QNativeAndroidViewGroup::onInflate(instance);
}

void QNativeAndroidRecyclerView::objectChange(ObjectChange change)
{
    QNativeAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QNativeAndroidRecyclerView::updateAdapter()
{
    Q_D(QNativeAndroidRecyclerView);
    if (!isValid() || !d->adapter)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject adapter = d->adapter->instance();
    QtNativeAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/support/v7/widget/RecyclerView$Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
