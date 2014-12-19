#include "qtqmlandroidalphaanimation_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidAlphaAnimation::QtQmlAndroidAlphaAnimation(QObject *parent) :
    QtQmlAndroidAnimation(parent), m_fromAlpha(0), m_toAlpha(0)
{
}

qreal QtQmlAndroidAlphaAnimation::fromAlpha() const
{
    return m_fromAlpha;
}

void QtQmlAndroidAlphaAnimation::setFromAlpha(qreal alpha)
{
    if (m_fromAlpha != alpha) {
        m_fromAlpha = alpha;
        emit fromAlphaChanged();
    }
}

qreal QtQmlAndroidAlphaAnimation::toAlpha() const
{
    return m_toAlpha;
}

void QtQmlAndroidAlphaAnimation::setToAlpha(qreal alpha)
{
    if (m_toAlpha != alpha) {
        m_toAlpha = alpha;
        emit toAlphaChanged();
    }
}

QAndroidJniObject QtQmlAndroidAlphaAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/AlphaAnimation",
                             "(FF)V",
                             m_fromAlpha, m_toAlpha);
}

QT_END_NAMESPACE
