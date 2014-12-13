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
                    hint: "Hint..."
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
    }
}
