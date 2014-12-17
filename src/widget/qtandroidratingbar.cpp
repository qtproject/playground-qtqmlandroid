#include "qtandroidratingbar_p.h"
#include "qtandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QtAndroidRatingBar::QtAndroidRatingBar(QtAndroidView *parent) :
    QtAndroidAbsSeekBar(parent), m_rating(0.0)
{
}

qreal QtAndroidRatingBar::rating() const
{
    return m_rating;
}

void QtAndroidRatingBar::setRating(qreal rating)
{
    if (updateRating(rating))
        QtAndroid::callRealMethod(instance(), "setRating", rating);
}

bool QtAndroidRatingBar::updateRating(qreal rating)
{
    if (!qFuzzyCompare(m_rating, rating)) {
        m_rating = rating;
        emit ratingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QtAndroidRatingBar::onCreate()
{
    return QAndroidJniObject("android/widget/RatingBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QtAndroidRatingBar::onInflate(QAndroidJniObject &instance)
{
    QtAndroidAbsSeekBar::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QtRatingBarListener",
                                   "(Landroid/widget/RatingBar;J)V",
                                   instance.object(),
                                   reinterpret_cast<jlong>(this));

    static bool nativeMethodsRegistered = false;
    if (!nativeMethodsRegistered) {
        onRegisterNativeMethods(m_listener.object());
        nativeMethodsRegistered = true;
    }

    instance.callMethod<void>("setRating", "(F)V", m_rating);
}

void QtAndroidRatingBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRatingChanged", "(JFZ)V", reinterpret_cast<void *>(onRatingChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QtAndroidRatingBar::onRatingChanged(JNIEnv *env, jobject object, jlong instance, jfloat rating, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QtAndroidRatingBar *bar = reinterpret_cast<QtAndroidRatingBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateRating", Qt::QueuedConnection, Q_ARG(qreal, rating));
}

QT_END_NAMESPACE
