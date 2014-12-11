package qtdroid.widget;

import android.widget.RadioGroup;
import android.widget.RadioButton;

public class QtRadioGroupListener implements RadioGroup.OnCheckedChangeListener
{
    public QtRadioGroupListener(RadioGroup group, long instance) {
        m_instance = instance;
        group.setOnCheckedChangeListener(this);
    }

    @Override
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        onCheckedChanged(m_instance, checkedId);
    }

    private long m_instance;
    private static native void onCheckedChanged(long instance, int checkedId);
}
