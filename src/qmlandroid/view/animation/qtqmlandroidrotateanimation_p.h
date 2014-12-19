#ifndef QTQMLANDROIDROTATEANIMATION_P_H
#define QTQMLANDROIDROTATEANIMATION_P_H

#include "qtqmlandroidanimation_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidRotateAnimation : public QtQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromDegrees READ fromDegrees WRITE setFromDegrees NOTIFY fromDegreesChanged)
    Q_PROPERTY(qreal toDegrees READ toDegrees WRITE setToDegrees NOTIFY toDegreesChanged)
    Q_PROPERTY(qreal pivotX READ pivotX WRITE setPivotX NOTIFY pivotXChanged)
    Q_PROPERTY(qreal pivotY READ pivotY WRITE setPivotY NOTIFY pivotYChanged)
    Q_PROPERTY(Relation pivotXType READ pivotXType WRITE setPivotXType NOTIFY pivotXTypeChanged)
    Q_PROPERTY(Relation pivotYType READ pivotYType WRITE setPivotYType NOTIFY pivotYTypeChanged)
    Q_ENUMS(Relation)

public:
    explicit QtQmlAndroidRotateAnimation(QObject *parent = 0);

    qreal fromDegrees() const;
    void setFromDegrees(qreal degrees);

    qreal toDegrees() const;
    void setToDegrees(qreal degrees);

    qreal pivotX() const;
    void setPivotX(qreal x);

    qreal pivotY() const;
    void setPivotY(qreal y);

    Relation pivotXType() const;
    void setPivotXType(Relation type);

    Relation pivotYType() const;
    void setPivotYType(Relation type);

Q_SIGNALS:
    void fromDegreesChanged();
    void toDegreesChanged();
    void pivotXChanged();
    void pivotYChanged();
    void pivotXTypeChanged();
    void pivotYTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    qreal m_from;
    qreal m_to;
    qreal m_pivotX;
    qreal m_pivotY;
    Relation m_pivotXType;
    Relation m_pivotYType;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDROTATEANIMATION_P_H
