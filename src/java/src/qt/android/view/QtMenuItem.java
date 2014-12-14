package qt.android.view;

import java.lang.CharSequence;
import android.view.MenuItem;

public class QtMenuItem implements MenuItem.OnMenuItemClickListener
{
    public QtMenuItem(long instance) {
        m_instance = instance;
        m_enabled = true;
        m_visible = true;
        m_checkable = false;
        m_checked = false;
    }

    public void create(MenuItem item) {
        item.setOnMenuItemClickListener(this);
        item.setTitle(m_title);
        item.setEnabled(m_enabled);
        item.setVisible(m_visible);
        item.setCheckable(m_checkable);
        item.setChecked(m_checked);
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

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        return onClick(m_instance);
    }

    private long m_instance;
    private CharSequence m_title;
    private boolean m_enabled;
    private boolean m_visible;
    private boolean m_checkable;
    private boolean m_checked;
    private static native boolean onClick(long instance);
}
