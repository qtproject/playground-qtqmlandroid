package qt.android.view;

import android.view.View;
import android.widget.AdapterView;

public class QmlViewListener implements View.OnClickListener,
                                        View.OnFocusChangeListener,
                                        View.OnLayoutChangeListener,
                                        View.OnLongClickListener
{
    public QmlViewListener(View view, long instance) {
        m_instance = instance;
        if (!(view instanceof AdapterView)) {
            view.setOnClickListener(this);
            view.setOnLongClickListener(this);
        }
        view.setOnFocusChangeListener(this);
        view.addOnLayoutChangeListener(this);
    }

    @Override
    public void onClick(View view) {
        onClick(m_instance);
    }

    @Override
    public void onFocusChange(View view, boolean hasFocus) {
        onFocusChange(m_instance, hasFocus);
    }

    @Override
    public void onLayoutChange(View view, int left, int top, int right, int bottom,
                                          int oldLeft, int oldTop, int oldRight, int oldBottom) {
        onLayoutChange(m_instance, left, top, right, bottom);
    }

    @Override
    public boolean onLongClick(View view) {
        return false; // TODO: onLongClick(m_instance);
    }

    private long m_instance;
    private static native void onClick(long instance);
    private static native void onFocusChange(long instance, boolean hasFocus);
    private static native void onLayoutChange(long instance, int left, int top, int right, int bottom);
    private static native boolean onLongClick(long instance);
}
