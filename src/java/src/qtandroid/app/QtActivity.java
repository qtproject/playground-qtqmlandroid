package qtdroid.app;

import java.lang.String;
import java.util.ArrayList;

import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.R.attr;
import android.util.TypedValue;

import android.view.Menu;
import android.view.MenuItem;

public class QtActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    public QtActivity() {
        m_menuItems = new ArrayList<String>();
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TypedValue attr = new TypedValue();
        getTheme().resolveAttribute(android.R.attr.windowBackground, attr, true);
        if (attr.type >= TypedValue.TYPE_FIRST_COLOR_INT && attr.type <= TypedValue.TYPE_LAST_COLOR_INT)
            getWindow().setBackgroundDrawable(new ColorDrawable(attr.data));
        else
            getWindow().setBackgroundDrawableResource(attr.resourceId);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        for (String title : m_menuItems)
            menu.add(title);
        return true;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        System.out.println("#### selected " + item.getTitle());
        return true;
    }

    @Override
    public void onOptionsMenuClosed(Menu menu) {
    }

    public void addOptionsMenuItem(String title) {
        m_menuItems.add(title);
        invalidateOptionsMenu();
    }

    ArrayList<String> m_menuItems;
}
