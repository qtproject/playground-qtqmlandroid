package qt.android.view;

import java.util.ArrayList;

import android.view.Menu;
import android.view.MenuItem;

import qt.android.view.QtMenuItem;

public class QtMenu
{
    public QtMenu() {
        m_items = new ArrayList<QtMenuItem>();
    }

    public void add(QtMenuItem item) {
        m_items.add(item);
    }

    public boolean create(Menu menu) {
        for (QtMenuItem item : m_items) {
            MenuItem mi = menu.add(item.getTitle());
            item.create(mi);
        }
        return true;
    }

    public boolean prepare(Menu menu) {
        return true;
    }

    public void closed(Menu menu) {
    }

    private ArrayList<QtMenuItem> m_items;
}
