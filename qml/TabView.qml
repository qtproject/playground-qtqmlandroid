import android.view 21.0
import android.widget 21.0

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            ListView {
                TabSpec.label: "ListView"
                adapter: ArrayAdapter {
                    array: ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"]
                }
            }
            CalendarView {
                TabSpec.label: "Calendar"
            }
        }
        TabWidget { }
    }
}
