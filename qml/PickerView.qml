import android.view 21.0
import android.widget 21.0

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            DatePicker {
                TabSpec.label: "DatePicker"
            }
            TimePicker {
                TabSpec.label: "TimePicker"
            }
        }
        TabWidget { }
    }
}
