import android.view 21.0
import android.widget 21.0
import android.support.v7.widget 21.0

ScrollView {
    LinearLayout {
        FrameLayout.topMargin: 48
        FrameLayout.leftMargin: 48
        FrameLayout.rightMargin: 48
        FrameLayout.bottomMargin: 48
        orientation: LinearLayout.VERTICAL

        CardView {
            LinearLayout {
                orientation: LinearLayout.VERTICAL
                FrameLayout.topMargin: 48
                FrameLayout.leftMargin: 48
                FrameLayout.rightMargin: 48
                FrameLayout.bottomMargin: 48

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
                orientation: LinearLayout.VERTICAL
                FrameLayout.topMargin: 48
                FrameLayout.leftMargin: 48
                FrameLayout.rightMargin: 48
                FrameLayout.bottomMargin: 48

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
                orientation: LinearLayout.VERTICAL
                FrameLayout.topMargin: 48
                FrameLayout.leftMargin: 48
                FrameLayout.rightMargin: 48
                FrameLayout.bottomMargin: 48

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
                orientation: LinearLayout.VERTICAL
                FrameLayout.topMargin: 48
                FrameLayout.leftMargin: 48
                FrameLayout.rightMargin: 48
                FrameLayout.bottomMargin: 48

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
                orientation: LinearLayout.VERTICAL
                FrameLayout.topMargin: 48
                FrameLayout.leftMargin: 48
                FrameLayout.rightMargin: 48
                FrameLayout.bottomMargin: 48

                TextView { text: "Switch"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                Switch { text: "Wifi"; checked: true }
                Switch { text: "Bluetooth" }
            }
        }
    }
}
