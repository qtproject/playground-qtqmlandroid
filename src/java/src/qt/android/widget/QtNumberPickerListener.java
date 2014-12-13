package qt.android.widget;

import android.widget.NumberPicker;

public class QtNumberPickerListener implements NumberPicker.OnValueChangeListener
{
    public QtNumberPickerListener(NumberPicker picker, long instance) {
        m_instance = instance;
        picker.setOnValueChangedListener(this);
    }

    @Override
    public void onValueChange(NumberPicker picker, int oldVal, int newVal) {
        onValueChange(m_instance, newVal);
    }

    private long m_instance;
    private static native void onValueChange(long instance, int value);
}
