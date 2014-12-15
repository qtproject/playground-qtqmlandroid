import android.app 21.0
import android.view 21.0
import android.widget 21.0
import android.graphics 21.0
import android.graphics.drawable 21.0
import android.support.v4.widget 21.0
import android.support.v7.app 21.0
import android.R 21.0

Activity {
    id: activity

    actionBar: ActionBar {
        title: "QtAndroid"
        subtitle: adapter.getItem(switcher.displayedChild)
        background: ColorDrawable {
            color: Color.rgb(255, 100, 100)
        }
    }

    optionsMenu: Menu {
        AlertDialog {
            id: dialog
            context: activity // TODO
            title: "About"
            message: "Native UI controls for Android"
        }
        MenuItem {
            title: "About"
            onClick: dialog.show()
        }
        MenuItem {
            title: "Exit"
            onClick: Qt.quit()
        }
    }

    DrawerLayout {
        id: drawer

        ActionBarDrawerToggle { }

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
