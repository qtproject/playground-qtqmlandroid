package qt.android.widget;

import android.widget.CompoundButton;

public class QmlCompoundButtonListener implements CompoundButton.OnCheckedChangeListener
{
    public QmlCompoundButtonListener(CompoundButton button, long instance) {
        m_instance = instance;
        button.setOnCheckedChangeListener(this);
    }

    @Override
    public void onCheckedChanged(CompoundButton button, boolean isChecked) {
        onCheckedChanged(m_instance, isChecked);
    }

    private long m_instance;
    private static native void onCheckedChanged(long instance, boolean isChecked);
}
