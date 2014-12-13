import android.view 21.0
import android.widget 21.0

ScrollView {
    LinearLayout {
        FrameLayout.topMargin: 48
        FrameLayout.leftMargin: 48
        FrameLayout.rightMargin: 48
        FrameLayout.bottomMargin: 48
        orientation: LinearLayout.VERTICAL

        TextView { text: "Button"; textSize: 18 }

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

        TextView { text: "ToggleButton"; textSize: 18 }

        LinearLayout {
            ToggleButton { checked: true }
            ToggleButton { }
        }

        TextView { textSize: 18; text: "CheckBox" }

        CheckBox { text: "E-mail"; checked: true }
        CheckBox { text: "Calendar" }
        CheckBox { text: "Contacts" }

        TextView { text: "RadioButton"; textSize: 18 }

        RadioGroup {
            RadioButton { text: "Portrait";  checked: true }
            RadioButton { text: "Landscape" }
            RadioButton { text: "Automatic" }
        }

        TextView { text: "Switch"; textSize: 18 }

        Switch { text: "Wifi"; checked: true }
        Switch { text: "Bluetooth" }
    }
}
