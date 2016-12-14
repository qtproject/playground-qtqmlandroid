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

#include "qqmlandroidrecyclerview_p.h"
#include "qqmlandroidrecycleradapter_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRecyclerView::QQmlAndroidRecyclerView(QQmlAndroidView *parent) :
    QQmlAndroidViewGroup(parent), m_adapter(0)
{
}

QQmlAndroidRecyclerAdapter *QQmlAndroidRecyclerView::adapter() const
{
    return m_adapter;
}

void QQmlAndroidRecyclerView::setAdapter(QQmlAndroidRecyclerAdapter *adapter)
{
    if (m_adapter != adapter) {
        if (m_adapter) {
            m_adapter->setContext(0);
            disconnect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidRecyclerView::updateAdapter);
            m_adapter->destruct();
        }
        m_adapter = adapter;
        if (m_adapter) {
            m_adapter->setContext(context());
            connect(m_adapter, &QQmlAndroidObject::instanceChanged, this, &QQmlAndroidRecyclerView::updateAdapter);
            if (isValid())
                m_adapter->construct();
        }
        emit adapterChanged();
    }}

QAndroidJniObject QQmlAndroidRecyclerView::onCreate()
{
    return QAndroidJniObject("android/support/v7/widget/RecyclerView",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRecyclerView::onInflate(QAndroidJniObject& instance)
{
    m_layoutManager = QAndroidJniObject("android/support/v7/widget/LinearLayoutManager",
                                        "(Landroid/content/Context;)V",
                                        ctx().object());

    instance.callMethod<void>("setLayoutManager",
                              "(Landroid/support/v7/widget/RecyclerView$LayoutManager;)V",
                              m_layoutManager.object());

    QQmlAndroidViewGroup::onInflate(instance);
}

void QQmlAndroidRecyclerView::objectChange(ObjectChange change)
{
    QQmlAndroidViewGroup::objectChange(change);
    if (change == InstanceChange)
        updateAdapter();
}

void QQmlAndroidRecyclerView::updateAdapter()
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
