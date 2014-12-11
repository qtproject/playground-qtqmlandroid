import android.app 0.1
import android.view 0.1
import android.widget 0.1
import android.support.v4.widget 0.1
import android.R 0.1

Activity {
    actionBar: ActionBar {
        title: "QtAndroid"
        subtitle: adapter.getItem(switcher.displayedChild)
    }

    optionsMenu: Menu {
        MenuItem {
            title: "Help"
        }
        MenuItem {
            title: "Exit"
        }
    }

    DrawerLayout {
        id: drawer

        ViewAnimator {
            id: switcher
            inAnimation: R.anim.slide_in_left
            outAnimation: R.anim.slide_out_right

            ButtonsView { }
            ProgressView { }
            InputView { }
            TabView { }
        }

        ListView {
            DrawerLayout.gravity: Gravity.LEFT
            adapter: ArrayAdapter {
                id: adapter
                array: ["Buttons", "Progress", "Input", "Views"]
            }
            onClick: {
                drawer.closeDrawer(Gravity.LEFT)
                switcher.displayedChild = position
            }
        }
    }
}
