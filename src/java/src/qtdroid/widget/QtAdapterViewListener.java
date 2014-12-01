package qtdroid.widget;

import android.view.View;
import android.widget.AdapterView;

public class QtAdapterViewListener implements AdapterView.OnItemClickListener
{
    public QtAdapterViewListener(AdapterView view, long instance) {
        m_instance = instance;
        view.setOnItemClickListener(this);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id)
    {
        onItemClick(m_instance, position);
    }

    private long m_instance;
    private static native void onItemClick(long instance, int position);
}
