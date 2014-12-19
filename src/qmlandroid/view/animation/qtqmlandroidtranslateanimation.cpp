#include "qtqmlandroidtranslateanimation_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidTranslateAnimation::QtQmlAndroidTranslateAnimation(QObject *parent) :
    QtQmlAndroidAnimation(parent), m_fromX(0), m_fromY(0), m_toX(0), m_toY(0),
    m_fromXType(ABSOLUTE), m_fromYType(ABSOLUTE), m_toXType(ABSOLUTE), m_toYType(ABSOLUTE)
{
}

qreal QtQmlAndroidTranslateAnimation::fromX() const
{
    return m_fromX;
}

void QtQmlAndroidTranslateAnimation::setFromX(qreal x)
{
    if (m_fromX != x) {
        m_fromX = x;
        emit fromXChanged();
    }
}

qreal QtQmlAndroidTranslateAnimation::fromY() const
{
    return m_fromY;
}

void QtQmlAndroidTranslateAnimation::setFromY(qreal y)
{
    if (m_fromY != y) {
        m_fromY = y;
        emit fromYChanged();
    }
}

qreal QtQmlAndroidTranslateAnimation::toX() const
{
    return m_toX;
}

void QtQmlAndroidTranslateAnimation::setToX(qreal x)
{
    if (m_toX != x) {
        m_toX = x;
        emit toXChanged();
    }
}

qreal QtQmlAndroidTranslateAnimation::toY() const
{
    return m_toY;
}

void QtQmlAndroidTranslateAnimation::setToY(qreal y)
{
    if (m_toY != y) {
        m_toY = y;
        emit toYChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidTranslateAnimation::fromXType() const
{
    return m_fromXType;
}

void QtQmlAndroidTranslateAnimation::setFromXType(Relation type)
{
    if (m_fromXType != type) {
        m_fromXType = type;
        emit fromXTypeChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidTranslateAnimation::fromYType() const
{
    return m_fromYType;
}

void QtQmlAndroidTranslateAnimation::setFromYType(Relation type)
{
    if (m_fromYType != type) {
        m_fromYType = type;
        emit fromYTypeChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidTranslateAnimation::toXType() const
{
    return m_toXType;
}

void QtQmlAndroidTranslateAnimation::setToXType(Relation type)
{
    if (m_toXType != type) {
        m_toXType = type;
        emit toXTypeChanged();
    }
}

QtQmlAndroidAnimation::Relation QtQmlAndroidTranslateAnimation::toYType() const
{
    return m_toYType;
}

void QtQmlAndroidTranslateAnimation::setToYType(Relation type)
{
    if (m_toYType != type) {
        m_toYType = type;
        emit toYTypeChanged();
    }
}

QAndroidJniObject QtQmlAndroidTranslateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/TranslateAnimation",
                             "(IFIFIFIF)V",
                             m_fromXType, m_fromX, m_toXType, m_toX,
                             m_fromYType, m_fromY, m_toYType, m_toY);
}

QT_END_NAMESPACE
