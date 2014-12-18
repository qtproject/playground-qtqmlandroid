#include "qtandroidtranslateanimation_p.h"

QT_BEGIN_NAMESPACE

QtAndroidTranslateAnimation::QtAndroidTranslateAnimation(QObject *parent) :
    QtAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_fromXType(ABSOLUTE), m_fromYType(ABSOLUTE), m_toXType(ABSOLUTE), m_toYType(ABSOLUTE)
{
}

qreal QtAndroidTranslateAnimation::fromX() const
{
    return m_fromX;
}

void QtAndroidTranslateAnimation::setFromX(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXChanged();
    }
}

qreal QtAndroidTranslateAnimation::fromY() const
{
    return m_fromY;
}

void QtAndroidTranslateAnimation::setFromY(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYChanged();
    }
}

qreal QtAndroidTranslateAnimation::toX() const
{
    return m_toX;
}

void QtAndroidTranslateAnimation::setToX(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXChanged();
    }
}

qreal QtAndroidTranslateAnimation::toY() const
{
    return m_toY;
}

void QtAndroidTranslateAnimation::setToY(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYChanged();
    }
}

QtAndroidAnimation::Relation QtAndroidTranslateAnimation::fromXType() const
{
    return m_fromXType;
}

void QtAndroidTranslateAnimation::setFromXType(Relation type)
{
    if (m_fromXType != type) {
        m_fromXType = type;
        emit fromXTypeChanged();
    }
}

QtAndroidAnimation::Relation QtAndroidTranslateAnimation::fromYType() const
{
    return m_fromYType;
}

void QtAndroidTranslateAnimation::setFromYType(Relation type)
{
    if (m_fromYType != type) {
        m_fromYType = type;
        emit fromYTypeChanged();
    }
}

QtAndroidAnimation::Relation QtAndroidTranslateAnimation::toXType() const
{
    return m_toXType;
}

void QtAndroidTranslateAnimation::setToXType(Relation type)
{
    if (m_toXType != type) {
        m_toXType = type;
        emit toXTypeChanged();
    }
}

QtAndroidAnimation::Relation QtAndroidTranslateAnimation::toYType() const
{
    return m_toYType;
}

void QtAndroidTranslateAnimation::setToYType(Relation type)
{
    if (m_toYType != type) {
        m_toYType = type;
        emit toYTypeChanged();
    }
}

QAndroidJniObject QtAndroidTranslateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/TranslateAnimation",
                             "(IFIFIFIF)V",
                             m_fromXType, m_fromX, m_toXType, m_toX,
                             m_fromYType, m_fromY, m_toYType, m_toY);
}

QT_END_NAMESPACE
