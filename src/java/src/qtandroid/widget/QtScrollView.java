package qtdroid.widget;

import android.content.Context;
import android.widget.ScrollView;

public class QtScrollView extends ScrollView
{
    public QtScrollView(Context context, long instance) {
        super(context);
        m_instance = instance;
    }

    @Override
    protected void onScrollChanged(int left, int top, int oldLeft, int oldTop) {
        onScrollChanged(m_instance, left, top);
    }

    private long m_instance;
    private static native void onScrollChanged(long instance, int left, int top);
}
