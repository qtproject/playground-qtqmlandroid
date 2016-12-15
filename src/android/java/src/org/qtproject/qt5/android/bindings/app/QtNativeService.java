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

package org.qtproject.qt5.android.bindings.app;

import android.app.Service;
import android.os.IBinder;
import android.content.Intent;

public class QtNativeService extends Service
{
    public QtNativeService() {
    }

    @Override
    public void onCreate() {
        System.out.println("### QtNativeService.onCreate");
        onCreated(0);
    }

    @Override
    public void onDestroy() {
        System.out.println("### QtNativeService.onDestroy");
        onDestroyed(0);
    }

    @Override
    public IBinder onBind(Intent intent) {
        long instance = intent.getLongExtra("QtNativeService", 0);
        System.out.println("### TODO: QtNativeService.onBind " + instance);
        return null;
    }

    @Override
    public void onRebind(Intent intent) {
        long instance = intent.getLongExtra("QtNativeService", 0);
        System.out.println("### TODO: QtNativeService.onRebind " + instance);
    }

    @Override
    public boolean onUnbind(Intent intent) {
        long instance = intent.getLongExtra("QtNativeService", 0);
        System.out.println("### TODO: QtNativeService.onUnbind " + instance);
        return false;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        long instance = intent.getLongExtra("QtNativeService", 0);
        System.out.println("### QtNativeService.onStartCommand " + instance);
        return onStartCommand(instance, flags, startId) ? START_STICKY : START_NOT_STICKY;
    }

    @Override
    public void onTaskRemoved(Intent rootIntent) {
        long instance = rootIntent.getLongExtra("QtNativeService", 0);
        System.out.println("### QtNativeService.onTaskRemoved " + instance);
    }

    private static native void onCreated(long instance);
    private static native void onDestroyed(long instance);
    private static native boolean onStartCommand(long instance, int flags, int startId);
}
