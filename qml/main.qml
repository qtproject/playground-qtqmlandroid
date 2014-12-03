import qtdroid.app 0.1
import qtdroid.view 0.1
import qtdroid.widget 0.1
import qtdroid.support.v4.widget 0.1

Activity {
    actionBar: ActionBar {
        title: "QtDroid"
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
