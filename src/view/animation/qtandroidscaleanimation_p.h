#ifndef QTANDROIDSCALEANIMATION_P_H
#define QTANDROIDSCALEANIMATION_P_H

#include "qtandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidScaleAnimation : public QtAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromXScale READ fromXScale WRITE setFromXScale NOTIFY fromXScaleChanged)
    Q_PROPERTY(qreal fromYScale READ fromYScale WRITE setFromYScale NOTIFY fromYScaleChanged)
    Q_PROPERTY(qreal toXScale READ toXScale WRITE setToXScale NOTIFY toXScaleChanged)
    Q_PROPERTY(qreal toYScale READ toYScale WRITE setToYScale NOTIFY toYScaleChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(PivotType pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(PivotType pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)

public:
    explicit QtAndroidScaleAnimation(QObject *parent = 0);

    qreal fromXScale() const;
    void setFromXScale(qreal scale);

    qreal fromYScale() const;
    void setFromYScale(qreal scale);

    qreal toXScale() const;
    void setToXScale(qreal scale);

    qreal toYScale() const;
    void setToYScale(qreal scale);

    qreal pivotX() const;
    void setPivotX(qreal x);

    qreal pivotY() const;
    void setPivotY(qreal y);

    PivotType pivotXType() const;
    void setPivotXType(PivotType type);

    PivotType pivotYType() const;
    void setPivotYType(PivotType type);

Q_SIGNALS:
    void fromXScaleChanged();
    void fromYScaleChanged();
    void toXScaleChanged();
    void toYScaleChanged();
    void pivotXChanged();
    void pivotYChanged();
    void pivotXTypeChanged();
    void pivotYTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    qreal m_fromX;
    qreal m_fromY;
    qreal m_toX;
    qreal m_toY;
    qreal m_pivotX;
    qreal m_pivotY;
    PivotType m_pivotXType;
    PivotType m_pivotYType;
};

QT_END_NAMESPACE

#endif // QTANDROIDSCALEANIMATION_P_H
