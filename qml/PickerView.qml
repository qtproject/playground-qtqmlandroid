import android.view 21.0
import android.widget 21.0

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        TabWidget { }
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            NumberPicker {
                TabSpec.label: "NumberPicker"
            }
            TimePicker {
                TabSpec.label: "TimePicker"
            }
        }
    }
}
