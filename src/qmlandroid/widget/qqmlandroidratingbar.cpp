#include "qqmlandroidratingbar_p.h"
#include "qtqmlandroidfunctions_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidRatingBar::QQmlAndroidRatingBar(QQmlAndroidView *parent) :
    QQmlAndroidAbsSeekBar(parent), m_rating(0.0)
{
}

qreal QQmlAndroidRatingBar::rating() const
{
    return m_rating;
}

void QQmlAndroidRatingBar::setRating(qreal rating)
{
    if (updateRating(rating))
        QtQmlAndroid::callRealMethod(instance(), "setRating", rating);
}

bool QQmlAndroidRatingBar::updateRating(qreal rating)
{
    if (!qFuzzyCompare(m_rating, rating)) {
        m_rating = rating;
        emit ratingChanged();
        return true;
    }
    return false;
}

QAndroidJniObject QQmlAndroidRatingBar::onCreate()
{
    return QAndroidJniObject("android/widget/RatingBar",
                             "(Landroid/content/Context;)V",
                             ctx().object());
}

void QQmlAndroidRatingBar::onInflate(QAndroidJniObject &instance)
{
    QQmlAndroidAbsSeekBar::onInflate(instance);

    m_listener = QAndroidJniObject("qt/android/widget/QmlRatingBarListener",
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

void QQmlAndroidRatingBar::onRegisterNativeMethods(jobject listener)
{
    JNINativeMethod methods[] {{"onRatingChanged", "(JFZ)V", reinterpret_cast<void *>(onRatingChanged)}};

    QAndroidJniEnvironment env;
    jclass cls = env->GetObjectClass(listener);
    env->RegisterNatives(cls, methods, sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(cls);
}

void QQmlAndroidRatingBar::onRatingChanged(JNIEnv *env, jobject object, jlong instance, jfloat rating, jboolean fromUser)
{
    Q_UNUSED(env);
    Q_UNUSED(object);
    QQmlAndroidRatingBar *bar = reinterpret_cast<QQmlAndroidRatingBar *>(instance);
    if (bar && fromUser)
        QMetaObject::invokeMethod(bar, "updateRating", Qt::QueuedConnection, Q_ARG(qreal, rating));
}

QT_END_NAMESPACE
