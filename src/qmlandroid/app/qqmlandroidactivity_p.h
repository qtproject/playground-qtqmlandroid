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

#ifndef QQMLANDROIDACTIVITY_P_H
#define QQMLANDROIDACTIVITY_P_H

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

#include <QtQmlAndroid/private/qqmlandroidcontextwrapper_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidView;
class QQmlAndroidMenu;
class QQmlAndroidWindow;
class QQmlAndroidActionBar;

class Q_QMLANDROID_EXPORT QQmlAndroidActivity : public QQmlAndroidContextWrapper
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidWindow *window READ window CONSTANT)
    Q_PROPERTY(QQmlAndroidActionBar *actionBar READ actionBar WRITE setActionBar)
    Q_PROPERTY(QQmlAndroidMenu *optionsMenu READ optionsMenu WRITE setOptionsMenu)
    Q_PROPERTY(QQmlAndroidView *contentView READ contentView WRITE setContentView)

public:
    explicit QQmlAndroidActivity(QObject *parent = nullptr);

    QQmlAndroidWindow *window() const;

    QQmlAndroidActionBar *actionBar() const;
    void setActionBar(QQmlAndroidActionBar *bar);

    QQmlAndroidMenu *optionsMenu() const;
    void setOptionsMenu(QQmlAndroidMenu *menu);

    QQmlAndroidView *contentView() const;
    void setContentView(QQmlAndroidView *view);

protected:
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    void setupWindow();
    void setupActionBar();
    void updateOptionsMenu();
    void invalidateOptionsMenu();
    void updateContentView();

private:
    QQmlAndroidWindow *m_window;
    QQmlAndroidView *m_contentView;
    QQmlAndroidMenu *m_optionsMenu;
    QQmlAndroidActionBar *m_actionBar;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACTIVITY_P_H
