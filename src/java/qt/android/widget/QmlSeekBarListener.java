package qt.android.widget;

import android.widget.SeekBar;

public class QmlSeekBarListener implements SeekBar.OnSeekBarChangeListener
{
    public QmlSeekBarListener(SeekBar seekBar, long instance) {
        m_instance = instance;
        seekBar.setOnSeekBarChangeListener(this);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        onProgressChanged(m_instance, progress, fromUser);
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
        // TODO
    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
        // TODO
    }

    private long m_instance;
    private static native void onProgressChanged(long instance, int progress, boolean fromUser);
}
