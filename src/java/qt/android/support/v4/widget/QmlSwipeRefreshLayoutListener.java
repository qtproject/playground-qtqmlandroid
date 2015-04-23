package qt.android.support.v4.widget;

import android.support.v4.widget.SwipeRefreshLayout;

public class QmlSwipeRefreshLayoutListener implements SwipeRefreshLayout.OnRefreshListener
{
    public QmlSwipeRefreshLayoutListener(SwipeRefreshLayout layout, long instance) {
        m_instance = instance;
        layout.setOnRefreshListener(this);
    }

    @Override
    public void onRefresh() {
        onRefresh(m_instance);
    }

    private long m_instance;
    private static native void onRefresh(long instance);
}
