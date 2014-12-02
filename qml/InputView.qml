import qtdroid.widget 0.1

ScrollView {
    LinearLayout {
        FrameLayout.topMargin: 48
        FrameLayout.leftMargin: 48
        FrameLayout.rightMargin: 48
        FrameLayout.bottomMargin: 48
        orientation: LinearLayout.VERTICAL

        TextView { text: "EditText"; textSize: 18 }

        EditText {
            hint: "Hint..."
        }

        TextView { text: "Spinner"; textSize: 18 }

        Spinner {
            adapter: ArrayAdapter {
                array: ["Apple", "Banana", "Orange"]
            }
        }
    }
}
