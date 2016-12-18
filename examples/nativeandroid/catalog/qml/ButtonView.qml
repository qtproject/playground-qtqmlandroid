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
import android.support.v7.widget 0.21

ScrollView {
    LinearLayout {
        padding: 48
        orientation: LinearLayout.VERTICAL

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "Button"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                LinearLayout {
                    Button { text: "Ok" }
                    Button {
                        text: "Cancel"
                        onClick: toast.show()
                        Toast {
                            id: toast
                            text: "Cancelled"
                        }
                    }
                    Space {
                        LinearLayout.weight: 1
                        LinearLayout.width: Layout.WRAP_CONTENT
                    }
                    Button {
                        text: "Attach"
                        onClick: menu.show()
                        PopupMenu {
                            id: menu
                            MenuItem { title: "Image" }
                            MenuItem { title: "Document" }
                        }
                    }
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "ToggleButton"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                LinearLayout {
                    ToggleButton { checked: true }
                    ToggleButton { }
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "CheckBox"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                CheckBox { text: "E-mail"; checked: true }
                CheckBox { text: "Calendar" }
                CheckBox { text: "Contacts" }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "RadioButton"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                RadioGroup {
                    RadioButton { text: "Portrait";  checked: true }
                    RadioButton { text: "Landscape" }
                    RadioButton { text: "Automatic" }
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "Switch"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                Switch { text: "Wifi"; checked: true }
                Space { LinearLayout.height: 24 }
                Switch { text: "Bluetooth" }
            }
        }
    }
}
