#include "qtandroidalphaanimation_p.h"

QT_BEGIN_NAMESPACE

QtAndroidAlphaAnimation::QtAndroidAlphaAnimation(QObject *parent) :
    QtAndroidAnimation(parent), m_fromAlpha(0), m_toAlpha(0)
{
}

qreal QtAndroidAlphaAnimation::fromAlpha() const
{
    return m_fromAlpha;
}

void QtAndroidAlphaAnimation::setFromAlpha(qreal alpha)
{
    if (m_fromAlpha != alpha) {
        m_fromAlpha = alpha;
        emit fromAlphaChanged();
    }
}

qreal QtAndroidAlphaAnimation::toAlpha() const
{
    return m_toAlpha;
}

void QtAndroidAlphaAnimation::setToAlpha(qreal alpha)
{
    if (m_toAlpha != alpha) {
        m_toAlpha = alpha;
        emit toAlphaChanged();
    }
}

QAndroidJniObject QtAndroidAlphaAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/AlphaAnimation",
                             "(FF)V",
                             m_fromAlpha, m_toAlpha);
}

QT_END_NAMESPACE
