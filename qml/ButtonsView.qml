import qtdroid.widget 0.1

ScrollView {
    LinearLayout {
        FrameLayout.topMargin: 48
        FrameLayout.leftMargin: 48
        FrameLayout.rightMargin: 48
        FrameLayout.bottomMargin: 48
        orientation: LinearLayout.VERTICAL

        TextView { text: "Button"; textSize: 48 }

        LinearLayout {
            Button { text: "Ok" }
            Button { text: "Cancel" }
        }

        TextView { text: "ToggleButton"; textSize: 48 }

        LinearLayout {
            ToggleButton { checked: true }
            ToggleButton { }
        }

        TextView { textSize: 48; text: "CheckBox" }

        CheckBox { text: "E-mail"; checked: true }
        CheckBox { text: "Calendar" }
        CheckBox { text: "Contacts" }

        TextView { text: "RadioButton"; textSize: 48 }

        RadioGroup {
            RadioButton { text: "Portrait";  checked: true }
            RadioButton { text: "Landscape" }
            RadioButton { text: "Automatic" }
        }

        TextView { text: "Switch"; textSize: 48 }

        Switch { text: "Wifi"; checked: true }
        Switch { text: "Bluetooth" }
    }
}
