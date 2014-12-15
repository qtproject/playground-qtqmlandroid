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
            ScrollView {
                TabSpec.label: "CardView"
                LinearLayout {
                    FrameLayout.topMargin: 48
                    FrameLayout.leftMargin: 48
                    FrameLayout.rightMargin: 48
                    FrameLayout.bottomMargin: 48
                    orientation: LinearLayout.VERTICAL
                    CardView {
                        RelativeLayout {
                            TextView { text: "Lorem"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout { TextView { text: "ipsum";  RelativeLayout.centerInParent: true } }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "dolor"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "sit"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "amet"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "consectetur"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "adipiscing"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                    Space { LinearLayout.height: 48 }
                    CardView {
                        RelativeLayout {
                            TextView { text: "elit"; RelativeLayout.centerInParent: true }
                        }
                        LinearLayout.height: 512
                    }
                }
            }
            RecyclerView {
                TabSpec.label: "RecyclerView"
                adapter: RecyclerAdapter {
                    array: ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"]
                }
            }
        }
        TabWidget { }
    }
}
