package qt.android.widget;

import android.widget.RatingBar;

public class QmlRatingBarListener implements RatingBar.OnRatingBarChangeListener
{
    public QmlRatingBarListener(RatingBar ratingBar, long instance) {
        m_instance = instance;
        ratingBar.setOnRatingBarChangeListener(this);
    }

    @Override
    public void onRatingChanged(RatingBar ratingBar, float rating, boolean fromUser) {
        onRatingChanged(m_instance, rating, fromUser);
    }

    private long m_instance;
    private static native void onRatingChanged(long instance, float rating, boolean fromUser);
}
