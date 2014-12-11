import android.widget 0.1

ScrollView {
    LinearLayout {
        FrameLayout.topMargin: 48
        FrameLayout.leftMargin: 48
        FrameLayout.rightMargin: 48
        FrameLayout.bottomMargin: 48
        orientation: LinearLayout.VERTICAL

        TextView { text: "ProgressBar"; textSize: 18 }

        LinearLayout {
            ProgressBar { style: ProgressBar.Large }
            ProgressBar { style: ProgressBar.Medium }
            ProgressBar { style: ProgressBar.Small }
        }

        TextView { text: "ProgressBar (horizontal)"; textSize: 18 }

        ProgressBar {
            indeterminate: true
            style: ProgressBar.Horizontal
        }
        ProgressBar {
            progress: seekBar.progress
            style: ProgressBar.Horizontal
        }

        TextView { text: "SeekBar"; textSize: 18 }

        SeekBar {
            id: seekBar
            progress: 50
        }
    }
}
