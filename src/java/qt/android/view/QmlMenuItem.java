package qt.android.view;

import java.lang.CharSequence;
import android.view.MenuItem;
import android.view.View;

public class QmlMenuItem implements MenuItem.OnMenuItemClickListener,
                                    MenuItem.OnActionExpandListener
{
    public QmlMenuItem(long instance) {
        m_instance = instance;
        m_enabled = true;
        m_visible = true;
        m_checkable = false;
        m_checked = false;
        m_showAs = MenuItem.SHOW_AS_ACTION_NEVER;
        m_actionView = null;
    }

    public void create(MenuItem item) {
        item.setOnMenuItemClickListener(this);
        item.setOnActionExpandListener(this);
        item.setTitle(m_title);
        item.setEnabled(m_enabled);
        item.setVisible(m_visible);
        item.setCheckable(m_checkable);
        item.setChecked(m_checked);
        item.setShowAsAction(m_showAs);
        item.setActionView(m_actionView);
    }

    public CharSequence getTitle() {
        return m_title;
    }

    public void setTitle(CharSequence title) {
        m_title = title;
    }

    public void setEnabled(boolean enabled) {
        m_enabled = enabled;
    }

    public void setVisible(boolean visible) {
        m_visible = visible;
    }

    public void setCheckable(boolean checkable) {
        m_checkable = checkable;
    }

    public void setChecked(boolean checked) {
        m_checked = checked;
    }

    public void setShowAs(int showAs) {
        m_showAs = showAs;
    }

    public void setActionView(View view) {
        m_actionView = view;
    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        return onClick(m_instance);
    }

    @Override
    public boolean onMenuItemActionCollapse(MenuItem item) {
        return onMenuItemActionCollapse(m_instance);
    }

    @Override
    public boolean onMenuItemActionExpand(MenuItem item) {
        return onMenuItemActionExpand(m_instance);
    }

    private long m_instance;
    private CharSequence m_title;
    private boolean m_enabled;
    private boolean m_visible;
    private boolean m_checkable;
    private boolean m_checked;
    private int m_showAs;
    private View m_actionView;
    private static native boolean onClick(long instance);
    private static native boolean onMenuItemActionCollapse(long instance);
    private static native boolean onMenuItemActionExpand(long instance);
}
