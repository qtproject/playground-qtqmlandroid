package qt.android.widget;

import android.widget.TabHost;

public class QtTabHostListener implements TabHost.OnTabChangeListener
{
    public QtTabHostListener(TabHost host, long instance) {
        m_instance = instance;
        host.setOnTabChangedListener(this);
    }

    @Override
    public void onTabChanged(String tabId) {
        System.out.println(tabId);
        onTabChanged(m_instance, tabId);
    }

    private long m_instance;
    private static native void onTabChanged(long instance, String tabId);
}
