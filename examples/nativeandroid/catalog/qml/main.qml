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

import android 0.21
import android.app 0.21
import android.view 0.21
import android.widget 0.21
import android.graphics 0.21
import android.graphics.drawable 0.21
import android.support.v4.widget 0.21
import android.support.v7.app 0.21

Activity {
    id: activity

    window.statusBarColor: Color.name("#455a64")

    actionBar: ActionBar {
        title: "QML for Android"
        subtitle: adapter.getItem(switcher.displayedChild)
        background: ColorDrawable {
            color: Color.name("#607d8b")
        }
    }

    optionsMenu: Menu {
        MenuItem {
            title: "Search"
            showAs: MenuItem.SHOW_AS_ACTION_ALWAYS
            visible: switcher.displayedChild == 2
            actionView: SearchView { }
        }
        MenuItem {
            title: "About"
            onClick: dialog.show()
        }
        MenuItem {
            title: "Exit"
            onClick: Qt.quit()
        }
    }

    AlertDialog {
        id: dialog
        title: "About"
        message: "QML wrappers for native Android controls."
    }

    contentView: DrawerLayout {
        id: drawer

        ActionBarDrawerToggle { }

        ViewAnimator {
            id: switcher
            inAnimation: R.anim.slide_in_left
            outAnimation: R.anim.slide_out_right

            ButtonView { }
            ProgressView { }
            InputView { }
            PickerView { }
            ModelView { }
            AwesomeView { }
        }

        ListView {
            DrawerLayout.gravity: Gravity.LEFT
            backgroundColor: Color.name("#eee")
            adapter: ArrayAdapter {
                id: adapter
                style: R.layout.simple_selectable_list_item
                array: ["Buttons", "Progress", "Input", "Pickers", "Views", "100%"]
            }
            onClick: {
                drawer.closeDrawer(Gravity.LEFT)
                switcher.displayedChild = position
            }
        }
    }
}
