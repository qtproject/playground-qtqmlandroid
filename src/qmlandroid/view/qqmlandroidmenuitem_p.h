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

#ifndef QQMLANDROIDMENUITEM_P_H
#define QQMLANDROIDMENUITEM_P_H

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

#include <QtQmlAndroid/private/qqmlandroidcontextual_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidView;

class Q_QMLANDROID_EXPORT QQmlAndroidMenuItem : public QQmlAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibleChanged)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable NOTIFY checkableChanged)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked NOTIFY checkedChanged)
    Q_PROPERTY(int showAs READ showAs WRITE setShowAs NOTIFY showAsChanged)
    Q_PROPERTY(QQmlAndroidView *actionView READ actionView WRITE setActionView NOTIFY actionViewChanged)
    Q_ENUMS(ShowAs)

public:
    explicit QQmlAndroidMenuItem(QObject *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);

    bool isEnabled() const;
    void setEnabled(bool enabled);

    bool isVisible() const;
    void setVisible(bool visible);

    bool isCheckable() const;
    void setCheckable(bool checkable);

    bool isChecked() const;
    void setChecked(bool checked);

    enum ShowAs {
        SHOW_AS_ACTION_NEVER = 0,
        SHOW_AS_ACTION_IF_ROOM = 1,
        SHOW_AS_ACTION_ALWAYS = 2,
        SHOW_AS_ACTION_WITH_TEXT = 4,
        SHOW_AS_ACTION_COLLAPSE_ACTION_VIEW = 8
    };

    int showAs() const;
    void setShowAs(int showAs);

    QQmlAndroidView *actionView() const;
    void setActionView(QQmlAndroidView *view);

Q_SIGNALS:
    void click();
    void titleChanged();
    void enabledChanged();
    void visibleChanged();
    void checkableChanged();
    void checkedChanged();
    void showAsChanged();
    void actionViewChanged();

protected:
    QAndroidJniObject onCreate() override;
    void onInflate(QAndroidJniObject &instance) override;

    static void onRegisterNativeMethods(jobject item);
    static bool onClick(JNIEnv *env, jobject object, jlong instance);
    static bool onMenuItemActionCollapse(JNIEnv *env, jobject object, jlong instance);
    static bool onMenuItemActionExpand(JNIEnv *env, jobject object, jlong instance);

    void objectChange(ObjectChange change) override;

private Q_SLOTS:
    void updateActionView();

private:
    QString m_title;
    bool m_enabled;
    bool m_visible;
    bool m_checkable;
    bool m_checked;
    int m_showAs;
    QQmlAndroidView *m_actionView;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDMENUITEM_P_H
