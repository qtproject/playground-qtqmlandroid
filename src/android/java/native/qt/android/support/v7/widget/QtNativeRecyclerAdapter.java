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

package qt.android.support.v7.widget;

import android.view.View;
import android.view.ViewGroup;
import android.support.v7.widget.RecyclerView;

import java.lang.Integer;

public class QtNativeRecyclerAdapter extends RecyclerView.Adapter<QtNativeRecyclerAdapter.ViewHolder>
{
    public QtNativeRecyclerAdapter(int count, long instance) {
        m_count = count;
        m_instance = instance;
    }

    @Override
    public int getItemCount() {
        return m_count;
    }

    public void setItemCount(int count) {
        if (m_count != count) {
            m_count = count;
            notifyDataSetChanged();
        }
    }

    public static class ViewHolder extends RecyclerView.ViewHolder
    {
        public ViewHolder(View view, long instance) {
            super(view);
            m_instance = instance;
        }
        public long getInstance() {
            return m_instance;
        }
        private long m_instance;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        ViewHolder vh = onCreateViewHolder(m_instance, parent, viewType);
        // TODO:
        RecyclerView.LayoutParams params = new RecyclerView.LayoutParams(-1, -2);
        vh.itemView.setLayoutParams(params);
        return vh;
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        onBindViewHolder(m_instance, holder, position);
    }

    @Override
    public void onViewRecycled(ViewHolder holder) {
        // TODO
    }

    private int m_count;
    private long m_instance;
    private static native ViewHolder onCreateViewHolder(long instance, ViewGroup parent, int viewType);
    private static native void onBindViewHolder(long instance, ViewHolder holder, int position);
}
