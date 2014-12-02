import qtdroid.app 0.1
import qtdroid.view 0.1
import qtdroid.widget 0.1
import qtdroid.support.v4.widget 0.1

Activity {
    actionBar: ActionBar {
        title: "QtDroid"
        subtitle: adapter.getItem(switcher.displayedChild)
    }

    DrawerLayout {
        id: drawer

        ViewAnimator {
            id: switcher

            ButtonsView { }
            ProgressView { }
            InputView { }
            CalendarView { }
        }

        ListView {
            DrawerLayout.gravity: Gravity.LEFT
            adapter: ArrayAdapter {
                id: adapter
                array: ["Buttons", "Progress", "Input", "Calendar"]
            }
            onClick: {
                drawer.closeDrawer(Gravity.LEFT)
                switcher.displayedChild = position
            }
        }

        ListView {
            DrawerLayout.gravity: Gravity.RIGHT
            adapter: ArrayAdapter {
                array: ["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19"]
            }
            onClick: drawer.closeDrawer(Gravity.RIGHT)
        }
    }
}
