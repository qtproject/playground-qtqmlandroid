package qt.android.view;

import java.util.ArrayList;

import android.view.Menu;
import android.view.MenuItem;

import qt.android.view.QmlMenuItem;

public class QmlMenu
{
    public QmlMenu() {
        m_items = new ArrayList<QmlMenuItem>();
    }

    public void add(QmlMenuItem item) {
        m_items.add(item);
    }

    public boolean create(Menu menu) {
        for (QmlMenuItem item : m_items) {
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

    private ArrayList<QmlMenuItem> m_items;
}
