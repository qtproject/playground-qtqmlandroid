#ifndef QTANDROIDROTATEANIMATION_P_H
#define QTANDROIDROTATEANIMATION_P_H

#include "qtandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRotateAnimation : public QtAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromDegrees READ fromDegrees WRITE setFromDegrees NOTIFY fromDegreesChanged)
    Q_PROPERTY(qreal toDegrees READ toDegrees WRITE setToDegrees NOTIFY toDegreesChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(PivotType pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(PivotType pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)
    Q_ENUMS(PivotType)

public:
    explicit QtAndroidRotateAnimation(QObject *parent = 0);

    qreal fromDegrees() const;
    void setFromDegrees(qreal degrees);

    qreal toDegrees() const;
    void setToDegrees(qreal degrees);

    qreal pivotX() const;
    void setPivotX(qreal x);

    qreal pivotY() const;
    void setPivotY(qreal y);

    PivotType pivotXType() const;
    void setPivotXType(PivotType type);

    PivotType pivotYType() const;
    void setPivotYType(PivotType type);

Q_SIGNALS:
    void fromDegreesChanged();
    void toDegreesChanged();
    void pivotXChanged();
    void pivotYChanged();
    void pivotXTypeChanged();
    void pivotYTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    qreal m_from;
    qreal m_to;
    qreal m_pivotX;
    qreal m_pivotY;
    PivotType m_pivotXType;
    PivotType m_pivotYType;
};

QT_END_NAMESPACE

#endif // QTANDROIDROTATEANIMATION_P_H
