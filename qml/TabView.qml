import android.view 21.0
import android.widget 21.0
import android.graphics 21.0
import android.graphics.drawable 21.0
import android.support.v4.widget 21.0
import android.support.v7.widget 21.0

import QtQml 2.1

TabHost {
    LinearLayout {
        orientation: LinearLayout.VERTICAL
        TabWidget { }
        FrameLayout {
            LinearLayout.weight: 1
            LinearLayout.height: Layout.WRAP_CONTENT
            SwipeRefreshLayout {
                id: layout
                TabSpec.label: "ListView"
                ListView {
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
            RecyclerView {
                TabSpec.label: "RecyclerView"
                adapter: RecyclerAdapter {
                    count: 50
                    delegate: FrameLayout {
                        CardView {
                            RelativeLayout {
                                padding: 48
                                ImageView {
                                    imageResource: 2130837556 // TODO: R.drawable.logo
                                    RelativeLayout.centerVertical: true
                                    RelativeLayout.alignParentLeft: true
                                }
                                TextView {
                                    text: position
                                    RelativeLayout.alignParentRight: true
                                    RelativeLayout.alignParentBottom: true
                                }
                            }
                            FrameLayout.margin: 48
                            FrameLayout.topMargin: position == 0 ? 48 : 0
                            FrameLayout.width: Layout.MATCH_PARENT
                        }
                    }
                }
            }
        }
    }
}
