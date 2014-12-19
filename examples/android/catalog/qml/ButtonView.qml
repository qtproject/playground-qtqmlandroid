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
