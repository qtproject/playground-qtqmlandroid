#include "qqmlandroidalphaanimation_p.h"

QT_BEGIN_NAMESPACE

QQmlAndroidAlphaAnimation::QQmlAndroidAlphaAnimation(QObject *parent) :
    QQmlAndroidAnimation(parent), m_fromAlpha(0), m_toAlpha(0)
{
}

qreal QQmlAndroidAlphaAnimation::fromAlpha() const
{
    return m_fromAlpha;
}

void QQmlAndroidAlphaAnimation::setFromAlpha(qreal alpha)
{
    if (m_fromAlpha != alpha) {
        m_fromAlpha = alpha;
        emit fromAlphaChanged();
    }
}

qreal QQmlAndroidAlphaAnimation::toAlpha() const
{
    return m_toAlpha;
}

void QQmlAndroidAlphaAnimation::setToAlpha(qreal alpha)
{
    if (m_toAlpha != alpha) {
        m_toAlpha = alpha;
        emit toAlphaChanged();
    }
}

QAndroidJniObject QQmlAndroidAlphaAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/AlphaAnimation",
                             "(FF)V",
                             m_fromAlpha, m_toAlpha);
}

QT_END_NAMESPACE
