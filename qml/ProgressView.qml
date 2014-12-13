import android.view 21.0
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

                TextView { text: "ProgressBar"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                LinearLayout {
                    ProgressBar { style: ProgressBar.Large }
                    Space { LinearLayout.width: 48 }
                    ProgressBar { style: ProgressBar.Medium }
                    Space { LinearLayout.width: 48 }
                    ProgressBar { style: ProgressBar.Small }
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: "ProgressBar (horizontal)"; textSize: 18 }
                Space { LinearLayout.height: 48 }
                ProgressBar {
                    indeterminate: true
                    style: ProgressBar.Horizontal
                }
                ProgressBar {
                    progress: seekBar.progress
                    style: ProgressBar.Horizontal
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: qsTr("SeekBar (%1)").arg(seekBar.progress); textSize: 18 }
                Space { LinearLayout.height: 48 }
                SeekBar {
                    id: seekBar
                    progress: 50
                }
            }
        }

        Space { LinearLayout.height: 48 }

        CardView {
            LinearLayout {
                padding: 48
                orientation: LinearLayout.VERTICAL

                TextView { text: qsTr("RatingBar (%1)").arg(ratingBar.rating); textSize: 18 }
                Space { LinearLayout.height: 48 }
                RatingBar {
                    id: ratingBar
                    rating: 3.5
                    LinearLayout.width: Layout.WRAP_CONTENT
                }
            }
        }
    }
}
