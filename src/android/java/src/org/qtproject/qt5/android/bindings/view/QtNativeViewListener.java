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

package org.qtproject.qt5.android.bindings.view;

import android.view.View;
import android.widget.AdapterView;

public class QtNativeViewListener implements View.OnClickListener,
                                        View.OnFocusChangeListener,
                                        View.OnLayoutChangeListener,
                                        View.OnLongClickListener
{
    public QtNativeViewListener(View view, long instance) {
        m_instance = instance;
        if (!(view instanceof AdapterView)) {
            view.setOnClickListener(this);
            view.setOnLongClickListener(this);
        }
        view.setOnFocusChangeListener(this);
        view.addOnLayoutChangeListener(this);
    }

    @Override
    public void onClick(View view) {
        onClick(m_instance);
    }

    @Override
    public void onFocusChange(View view, boolean hasFocus) {
        onFocusChange(m_instance, hasFocus);
    }

    @Override
    public void onLayoutChange(View view, int left, int top, int right, int bottom,
                                          int oldLeft, int oldTop, int oldRight, int oldBottom) {
        onLayoutChange(m_instance, left, top, right, bottom);
    }

    @Override
    public boolean onLongClick(View view) {
        return false; // TODO: onLongClick(m_instance);
    }

    private long m_instance;
    private static native void onClick(long instance);
    private static native void onFocusChange(long instance, boolean hasFocus);
    private static native void onLayoutChange(long instance, int left, int top, int right, int bottom);
    private static native boolean onLongClick(long instance);
}
