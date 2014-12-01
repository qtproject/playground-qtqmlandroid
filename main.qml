import qtdroid.app 0.1
import qtdroid.view 0.1
import qtdroid.widget 0.1
import qtdroid.support.v4.widget 0.1

//import QtQuick 2.0 // color

Activity {
    actionBar: ActionBar {
        title: "ActionBar"
    }

    DrawerLayout {
        id: drawer

        ScrollView {
            DrawerLayout.gravity: Gravity.NO_GRAVITY
            DrawerLayout.height: Layout.MATCH_PARENT

            LinearLayout {
                orientation: LinearLayout.VERTICAL

                TextView {
                    text: "Button"
                    textSize: 48
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
                    textSize: 48
                }

                LinearLayout {
                    ToggleButton { }
                    ToggleButton { }
                    ToggleButton { }
                }

                TextView {
                    text: "CheckBox"
                    textSize: 48
                }

                LinearLayout {
                    CheckBox {
                        checked: true
                        text: "First"
                        onCheckedChanged: console.log(text, checked)
                    }
                    CheckBox {
                        text: "Second"
                        onCheckedChanged: console.log(text, checked)
                    }
                    CheckBox {
                        text: "Third"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "RadioButton"
                    textSize: 48
                }

                RadioGroup {
                    RadioButton {
                        checked: true
                        text: "First"
                        onCheckedChanged: console.log(text, checked)
                    }
                    RadioButton {
                        text: "Second"
                        onCheckedChanged: console.log(text, checked)
                    }
                    RadioButton {
                        text: "Third"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "Switch"
                    textSize: 48
                }

                LinearLayout {
                    Switch {
                        checked: true
                        text: "First"
                        onCheckedChanged: console.log(text, checked)
                    }
                    Switch {
                        text: "Second"
                        onCheckedChanged: console.log(text, checked)
                    }
                    Switch {
                        text: "Third"
                        onCheckedChanged: console.log(text, checked)
                    }
                }

                TextView {
                    text: "ProgressBar"
                    textSize: 48
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
                    textSize: 48
                }

                SeekBar {
                    id: seekBar
                    progress: 50
                }

                TextView {
                    text: "EditText"
                    textSize: 48
                }

                EditText {
                    hint: "Hint..."
                }
            }
        }

        ListView {
            DrawerLayout.gravity: Gravity.LEFT

            adapter: ArrayAdapter {
                id: adapter
                array: ["Buttons", "Progress", "Input"]
            }
            onClick: console.log(position, adapter.getItem(position))
        }
    }
}
