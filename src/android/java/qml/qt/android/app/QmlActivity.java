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

package qt.android.app;

import java.util.ArrayList;

import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.R.attr;
import android.util.TypedValue;

import android.view.Menu;

import qt.android.view.QmlMenu;

public class QmlActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    public QmlActivity() {
        m_menu = null;
    }

    public void setOptionsMenu(QmlMenu menu) {
        if (m_menu != menu) {
            m_menu = menu;
            invalidateOptionsMenu();
        }
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TypedValue attr = new TypedValue();
        getTheme().resolveAttribute(android.R.attr.windowBackground, attr, true);
        if (attr.type >= TypedValue.TYPE_FIRST_COLOR_INT && attr.type <= TypedValue.TYPE_LAST_COLOR_INT)
            getWindow().setBackgroundDrawable(new ColorDrawable(attr.data));
        else
            getWindow().setBackgroundDrawableResource(attr.resourceId);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        if (m_menu != null)
            return m_menu.create(menu);
        return false;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        if (m_menu != null)
            return m_menu.prepare(menu);
        return false;
    }

    @Override
    public void onOptionsMenuClosed(Menu menu) {
        m_menu.closed(menu);
    }

    private QmlMenu m_menu;
}
