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
#include "qnativeandroidrecycleradapter_p.h"
#include "qtnativeandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QNativeAndroidRecyclerView::QNativeAndroidRecyclerView(QNativeAndroidContext *context) :
    QNativeAndroidViewGroup(context), m_adapter(0)
{
}

QNativeAndroidRecyclerAdapter *QNativeAndroidRecyclerView::adapter() const
{
    return m_adapter;
}

void QNativeAndroidRecyclerView::setAdapter(QNativeAndroidRecyclerAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidRecyclerView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QNativeAndroidObject::instanceChanged, this, &QNativeAndroidRecyclerView::updateAdapter);
            if (isValid())
                m_adapter->construct();
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
    m_layoutManager = QAndroidJniObject("android/support/v7/widget/LinearLayoutManager",
                                        "(Landroid/content/Context;)V",
                                        ctx().object());

    instance.callMethod<void>("setLayoutManager",
                              "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                              m_layoutManager.object());

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
    if (!isValid() || !m_adapter)
        return;

    QAndroidJniObject view = instance();
    QAndroidJniObject adapter = m_adapter->instance();
    QtQmlAndroid::callFunction([=]() {
        view.callMethod<void>("setAdapter", "(Landroid/support/v7/widget/RecyclerView$Adapter;)V", adapter.object());
    });
}

QT_END_NAMESPACE
