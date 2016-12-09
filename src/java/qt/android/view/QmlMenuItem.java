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

package qt.android.view;

import java.lang.CharSequence;
import android.view.MenuItem;
import android.view.View;

public class QmlMenuItem implements MenuItem.OnMenuItemClickListener,
                                    MenuItem.OnActionExpandListener
{
    public QmlMenuItem(long instance) {
        m_instance = instance;
        m_enabled = true;
        m_visible = true;
        m_checkable = false;
        m_checked = false;
        m_showAs = MenuItem.SHOW_AS_ACTION_NEVER;
        m_actionView = null;
    }

    public void create(MenuItem item) {
        item.setOnMenuItemClickListener(this);
        item.setOnActionExpandListener(this);
        item.setTitle(m_title);
        item.setEnabled(m_enabled);
        item.setVisible(m_visible);
        item.setCheckable(m_checkable);
        item.setChecked(m_checked);
        item.setShowAsAction(m_showAs);
        item.setActionView(m_actionView);
    }

    public CharSequence getTitle() {
        return m_title;
    }

    public void setTitle(CharSequence title) {
        m_title = title;
    }

    public void setEnabled(boolean enabled) {
        m_enabled = enabled;
    }

    public void setVisible(boolean visible) {
        m_visible = visible;
    }

    public void setCheckable(boolean checkable) {
        m_checkable = checkable;
    }

    public void setChecked(boolean checked) {
        m_checked = checked;
    }

    public void setShowAs(int showAs) {
        m_showAs = showAs;
    }

    public void setActionView(View view) {
        m_actionView = view;
    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        return onClick(m_instance);
    }

    @Override
    public boolean onMenuItemActionCollapse(MenuItem item) {
        return onMenuItemActionCollapse(m_instance);
    }

    @Override
    public boolean onMenuItemActionExpand(MenuItem item) {
        return onMenuItemActionExpand(m_instance);
    }

    private long m_instance;
    private CharSequence m_title;
    private boolean m_enabled;
    private boolean m_visible;
    private boolean m_checkable;
    private boolean m_checked;
    private int m_showAs;
    private View m_actionView;
    private static native boolean onClick(long instance);
    private static native boolean onMenuItemActionCollapse(long instance);
    private static native boolean onMenuItemActionExpand(long instance);
}
