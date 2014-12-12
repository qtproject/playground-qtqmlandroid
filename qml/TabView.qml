import android.view 21.0
import android.widget 21.0
import android.support.v4.widget 21.0

import QtQml 2.1

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            SwipeRefreshLayout {
                id: layout
                ListView {
                    TabSpec.label: "ListView"
                    adapter: ArrayAdapter {
                        array: ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"]
                    }
                }
                Timer {
                    interval: 2000
                    running: layout.refreshing
                    onTriggered: layout.refreshing = false
                }
            }
            CalendarView {
                TabSpec.label: "Calendar"
            }
        }
        TabWidget { }
    }
}
