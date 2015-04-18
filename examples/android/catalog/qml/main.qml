import android 0.21
import android.app 0.21
import android.view 0.21
import android.widget 0.21
import android.graphics 0.21
import android.graphics.drawable 0.21
import android.support.v4.widget 0.21
import android.support.v7.app 0.21

Activity {
    id: activity

    window.statusBarColor: Color.name("#455a64")

    actionBar: ActionBar {
        title: "QML for Android"
        subtitle: adapter.getItem(switcher.displayedChild)
        background: ColorDrawable {
            color: Color.name("#607d8b")
        }
    }

    optionsMenu: Menu {
        MenuItem {
            title: "Search"
            showAs: MenuItem.SHOW_AS_ACTION_ALWAYS
            visible: switcher.displayedChild == 2
            actionView: SearchView { }
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

    AlertDialog {
        id: dialog
        title: "About"
        message: "QML wrappers for native Android controls."
    }

    contentView: DrawerLayout {
        id: drawer

        ActionBarDrawerToggle { }

        ViewAnimator {
            id: switcher
            inAnimation: R.anim.slide_in_left
            outAnimation: R.anim.slide_out_right

            ButtonView { }
            ProgressView { }
            InputView { }
            PickerView { }
            ModelView { }
            AwesomeView { }
        }

        ListView {
            DrawerLayout.gravity: Gravity.LEFT
            backgroundColor: Color.name("#eee")
            adapter: ArrayAdapter {
                id: adapter
                style: R.layout.simple_selectable_list_item
                array: ["Buttons", "Progress", "Input", "Pickers", "Views", "100%"]
            }
            onClick: {
                drawer.closeDrawer(Gravity.LEFT)
                switcher.displayedChild = position
            }
        }
    }
}
