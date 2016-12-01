import android.view 0.21
import android.widget 0.21
import android.view.animation 0.21

RelativeLayout {
    ImageView {
        imageResource: 2130837555 // TODO: R.drawable.awesome
        RelativeLayout.centerInParent: true

//        animation: Animation {
//            id: anim
//            resource: 2130968582 // TODO: r.anim.awesome
//        }

        animation: AnimationSet {
            id: anim
            shareInterpolator: false
            ScaleAnimation {
                duration: 4800
                repeatMode: Animation.REVERSE
                repeatCount: Animation.INFINITE
                fromXScale: 0.5
                fromYScale: 0.5
                toXScale: 1.0
                toYScale: 1.0
                pivotX: 0.5 // "50%"
                pivotY: 0.5 // "50%"
                pivotXType: Animation.RELATIVE_TO_SELF
                pivotYType: Animation.RELATIVE_TO_SELF
                interpolator: AccelerateDecelerateInterpolator { }
            }
            RotateAnimation {
                duration: 3200
                repeatCount: Animation.INFINITE
                fromDegrees: 0
                toDegrees: -360
                pivotX: 0.5 // "50%"
                pivotY: 0.5 // "50%"
                pivotXType: Animation.RELATIVE_TO_SELF
                pivotYType: Animation.RELATIVE_TO_SELF
                interpolator: LinearInterpolator { }
            }
        }
    }
}
