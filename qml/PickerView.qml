import android.view 0.21
import android.widget 0.21

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
