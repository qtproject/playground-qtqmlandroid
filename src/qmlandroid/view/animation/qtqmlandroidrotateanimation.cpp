#include "qtqmlandroidrotateanimation_p.h"

QT_BEGIN_NAMESPACE

QtQmlAndroidRotateAnimation::QtQmlAndroidRotateAnimation(QObject *parent) :
    QtQmlAndroidAnimation(parent), m_from(0), m_to(0),
    m_pivotX(0), m_pivotY(0), m_pivotXType(ABSOLUTE), m_pivotYType(ABSOLUTE)
{
}

qreal QtQmlAndroidRotateAnimation::fromDegrees() const
{
    return m_from;
}

void QtQmlAndroidRotateAnimation::setFromDegrees(qreal degrees)
{
    if (m_from != degrees) {
        m_from = degrees;
        emit fromDegreesChanged();
    }
}

qreal QtQmlAndroidRotateAnimation::toDegrees() const
{
    return m_to;
}

void QtQmlAndroidRotateAnimation::setToDegrees(qreal degrees)
{
    if (m_to != degrees) {
        m_to = degrees;
        emit toDegreesChanged();
    }
}

qreal QtQmlAndroidRotateAnimation::pivotX() const
{
    return m_pivotX;
}

void QtQmlAndroidRotateAnimation::setPivotX(qreal pivotX)
{
    if (m_pivotX != pivotX) {
        m_pivotX = pivotX;
        emit pivotXChanged();
    }
}

qreal QtQmlAndroidRotateAnimation::pivotY() const
{
    return m_pivotY;
}

void QtQmlAndroidRotateAnimation::setPivotY(qreal pivotY)
{
    if (m_pivotY != pivotY) {
        m_pivotY = pivotY;
        emit pivotYChanged();
    }
}

QtQmlAndroidRotateAnimation::Relation QtQmlAndroidRotateAnimation::pivotXType() const
{
    return m_pivotXType;
}

void QtQmlAndroidRotateAnimation::setPivotXType(Relation type)
{
    if (m_pivotXType != type) {
        m_pivotXType = type;
        emit pivotXTypeChanged();
    }
}

QtQmlAndroidRotateAnimation::Relation QtQmlAndroidRotateAnimation::pivotYType() const
{
    return m_pivotYType;
}

void QtQmlAndroidRotateAnimation::setPivotYType(Relation type)
{
    if (m_pivotYType != type) {
        m_pivotYType = type;
        emit pivotYTypeChanged();
    }
}

QAndroidJniObject QtQmlAndroidRotateAnimation::onCreate()
{
    return QAndroidJniObject("android/view/animation/RotateAnimation",
                             "(FFIFIF)V",
                             m_from, m_to,
                             m_pivotXType, m_pivotX, m_pivotYType, m_pivotY);
}

QT_END_NAMESPACE
