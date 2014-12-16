#ifndef QTANDROIDRATINGBAR_P_H
#define QTANDROIDRATINGBAR_P_H

#include "qtandroidabsseekbar_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRatingBar : public QtAndroidAbsSeekBar
{
    Q_OBJECT
    Q_PROPERTY(qreal rating READ rating WRITE setRating NOTIFY ratingChanged)

public:
    explicit QtAndroidRatingBar(QtAndroidView *parent = 0);

    qreal rating() const;
    void setRating(qreal rating);

Q_SIGNALS:
    void ratingChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    static void onRegisterNativeMethods(jobject listener);
    static void onRatingChanged(JNIEnv *env, jobject object, jlong instance, jfloat rating, jboolean fromUser);

private Q_SLOTS:
    bool updateRating(qreal rating);

private:
    qreal m_rating;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDRATINGBAR_P_H
