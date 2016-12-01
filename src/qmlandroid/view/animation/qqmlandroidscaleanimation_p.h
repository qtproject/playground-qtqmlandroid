#ifndef QQMLANDROIDSCALEANIMATION_P_H
#define QQMLANDROIDSCALEANIMATION_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidScaleAnimation : public QQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromXScale READ fromXScale WRITE setFromXScale NOTIFY fromXScaleChanged)
    Q_PROPERTY(qreal fromYScale READ fromYScale WRITE setFromYScale NOTIFY fromYScaleChanged)
    Q_PROPERTY(qreal toXScale READ toXScale WRITE setToXScale NOTIFY toXScaleChanged)
    Q_PROPERTY(qreal toYScale READ toYScale WRITE setToYScale NOTIFY toYScaleChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(Relation pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(Relation pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)

public:
    explicit QQmlAndroidScaleAnimation(QObject *parent = 0);

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

    Relation pivotXType() const;
    void setPivotXType(Relation type);

    Relation pivotYType() const;
    void setPivotYType(Relation type);

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

private:
    qreal m_fromX;
    qreal m_fromY;
    qreal m_toX;
    qreal m_toY;
    qreal m_pivotX;
    qreal m_pivotY;
    Relation m_pivotXType;
    Relation m_pivotYType;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSCALEANIMATION_P_H
