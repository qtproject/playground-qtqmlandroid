import qtdroid.app 0.1
import qtdroid.view 0.1
import qtdroid.widget 0.1
import qtdroid.support.v4.widget 0.1

import QtQuick 2.0 // color

Activity {
    actionBar: ActionBar {
        title: "ActionBar"
    }

    DrawerLayout {

        ScrollView {
            DrawerLayout.gravity: 0 // NONE
            DrawerLayout.height: Layout.MATCH_PARENT

            LinearLayout {

                orientation: LinearLayout.VERTICAL

                TextView {
                    text: "Button"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                LinearLayout {
                    Button {
                        text: "First"
                    }
                    Button {
                        text: "Second"
                    }
                    Button {
                        text: "Third"
                    }
                }

                TextView {
                    text: "ToggleButton"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                LinearLayout {
                    ToggleButton { }
                    ToggleButton { }
                    ToggleButton { }
                }

                TextView {
                    text: "CheckBox"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                LinearLayout {
                    CheckBox {
                        checked: true
                        text: "First"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    CheckBox {
                        text: "Second"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    CheckBox {
                        text: "Third"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "RadioButton"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                RadioGroup {
                    RadioButton {
                        checked: true
                        text: "First"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    RadioButton {
                        text: "Second"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    RadioButton {
                        text: "Third"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "Switch"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                LinearLayout {
                    Switch {
                        checked: true
                        text: "First"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    Switch {
                        text: "Second"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                    Switch {
                        text: "Third"
                        textColor: "white"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "ProgressBar"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                LinearLayout {
                    ProgressBar {
                        style: ProgressBar.Small
                    }
                    ProgressBar {
                        style: ProgressBar.Medium
                    }
                    ProgressBar {
                        style: ProgressBar.Large
                    }
                }
                ProgressBar {
                    indeterminate: true
                    style: ProgressBar.Horizontal
                }
                ProgressBar {
                    progress: seekBar.progress
                    style: ProgressBar.Horizontal
                }

                TextView {
                    text: "SeekBar"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                SeekBar {
                    id: seekBar
                    progress: 50
                }

                TextView {
                    text: "EditText"
                    textSize: 72
                    textColor: Qt.rgba(1,1,1,1)
                }

                EditText {
                    hint: "Hint..."
                    textColor: "white"
                }
            }
        }

        LinearLayout {
            orientation: LinearLayout.VERTICAL

            DrawerLayout.gravity: 3 // LEFT
            DrawerLayout.width: 600
            DrawerLayout.height: Layout.MATCH_PARENT

            TextView {
                text: "Hello"
                textColor: "white"
            }
            TextView {
                text: "Cute"
                textColor: "white"
            }
            TextView {
                text: "Hello"
                textColor: "white"
            }
        }
    }
}
