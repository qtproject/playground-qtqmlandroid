import android.widget 21.0
import android.support.v7.widget 21.0

ScrollView {
    LinearLayout {
        padding: 48
        orientation: LinearLayout.VERTICAL

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "EditText"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                EditText {
                    hint: "Username"
                    singleLine: true
                }
                Space { LinearLayout.height: 48 }
                EditText {
                    hint: "Password"
                    singleLine: true
                    inputType: 1 | 128 // TODO: TYPE_CLASS_TEXT | TYPE_TEXT_VARIATION_VISIBLE_PASSWORD
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "Spinner"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                Spinner {
                    adapter: ArrayAdapter {
                        array: ["Apple", "Banana", "Orange"]
                    }
                }
            }
        }

//        Space { LinearLayout.height: 48 }

//        CardView {
//            LinearLayout {
//                padding: 48
//                orientation: LinearLayout.VERTICAL

//                TextView { text: qsTr("NumberPicker (%1)").arg(picker.value); textSize: 18 }
//                Space { LinearLayout.height: 48 }
//                NumberPicker {
//                    id: picker
//                    value: 13
//                }
//            }
//        }
    }
}
