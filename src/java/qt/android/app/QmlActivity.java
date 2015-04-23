package qt.android.app;

import java.util.ArrayList;

import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.R.attr;
import android.util.TypedValue;

import android.view.Menu;

import qt.android.view.QmlMenu;

public class QmlActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
    public QmlActivity() {
        m_menu = null;
    }

    public void setOptionsMenu(QmlMenu menu) {
        if (m_menu != menu) {
            m_menu = menu;
            invalidateOptionsMenu();
        }
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
        if (m_menu != null)
            return m_menu.create(menu);
        return false;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        if (m_menu != null)
            return m_menu.prepare(menu);
        return false;
    }

    @Override
    public void onOptionsMenuClosed(Menu menu) {
        m_menu.closed(menu);
    }

    private QmlMenu m_menu;
}
