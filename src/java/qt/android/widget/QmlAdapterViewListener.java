package qt.android.widget;

import android.view.View;
import android.widget.Spinner;
import android.widget.AdapterView;

public class QmlAdapterViewListener implements AdapterView.OnItemClickListener
{
    public QmlAdapterViewListener(AdapterView view, long instance) {
        m_instance = instance;
        if (!(view instanceof Spinner)) {
            view.setOnItemClickListener(this);
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id)
    {
        onItemClick(m_instance, position);
    }

    private long m_instance;
    private static native void onItemClick(long instance, int position);
}
