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

#ifndef QQMLANDROIDRECYCLERVIEW_P_H
#define QQMLANDROIDRECYCLERVIEW_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQmlAndroid/private/qqmlandroidviewgroup_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidRecyclerAdapter;

class Q_QMLANDROID_EXPORT QQmlAndroidRecyclerView : public QQmlAndroidViewGroup
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidRecyclerAdapter *adapter READ adapter WRITE setAdapter NOTIFY adapterChanged)

public:
    explicit QQmlAndroidRecyclerView(QQmlAndroidView *parent = nullptr);

    QQmlAndroidRecyclerAdapter *adapter() const;
    void setAdapter(QQmlAndroidRecyclerAdapter *adapter);

Q_SIGNALS:
    void adapterChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

    void objectChange(ObjectChange change) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void updateAdapter();

private:
    QQmlAndroidRecyclerAdapter *m_adapter;
    QAndroidJniObject m_layoutManager;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRECYCLERVIEW_P_H
