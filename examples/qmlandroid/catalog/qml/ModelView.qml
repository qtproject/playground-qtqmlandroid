/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import android.view 0.21
import android.widget 0.21
import android.graphics 0.21
import android.graphics.drawable 0.21
import android.support.v4.widget 0.21
import android.support.v7.widget 0.21

import QtQml 2.1

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        TabWidget { }
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            SwipeRefreshLayout {
                id: layout
                TabSpec.label: "ListView"
                ListView {
                    adapter: ArrayAdapter {
                        array: ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"]
                    }
                }
                Timer {
                    interval: 2000
                    running: layout.refreshing
                    onTriggered: layout.refreshing = false
                }
            }
            RecyclerView {
                TabSpec.label: "RecyclerView"
                adapter: RecyclerAdapter {
                    count: 50
                    delegate: FrameLayout {
                        CardView {
                            RelativeLayout {
                                padding: 48
                                ImageView {
                                    imageResource: 2130837556 // TODO: R.drawable.logo
                                    RelativeLayout.centerVertical: true
                                    RelativeLayout.alignParentLeft: true
                                }
                                TextView {
                                    text: position
                                    RelativeLayout.alignParentRight: true
                                    RelativeLayout.alignParentBottom: true
                                }
                            }
                            FrameLayout.margin: 48
                            FrameLayout.topMargin: position == 0 ? 48 : 0
                            FrameLayout.width: Layout.MATCH_PARENT
                        }
                    }
                }
            }
        }
    }
}
