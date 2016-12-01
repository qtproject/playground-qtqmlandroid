#ifndef QQMLANDROIDTRANSLATEANIMATION_P_H
#define QQMLANDROIDTRANSLATEANIMATION_P_H

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

class QQmlAndroidTranslateAnimation : public QQmlAndroidAnimation
{
    Q_OBJECT
    Q_PROPERTY(qreal fromX READ fromX WRITE setFromX NOTIFY fromXChanged)
    Q_PROPERTY(qreal fromY READ fromY WRITE setFromY NOTIFY fromYChanged)
    Q_PROPERTY(qreal toX READ toX WRITE setToX NOTIFY toXChanged)
    Q_PROPERTY(qreal toY READ toY WRITE setToY NOTIFY toYChanged)
    Q_PROPERTY(Relation fromXType READ fromXType WRITE setFromXType NOTIFY fromXTypeChanged)
    Q_PROPERTY(Relation fromYType READ fromYType WRITE setFromYType NOTIFY fromYTypeChanged)
    Q_PROPERTY(Relation toXType READ toXType WRITE setToXType NOTIFY toXTypeChanged)
    Q_PROPERTY(Relation toYType READ toYType WRITE setToYType NOTIFY toYTypeChanged)

public:
    explicit QQmlAndroidTranslateAnimation(QObject *parent = 0);

    qreal fromX() const;
    void setFromX(qreal x);

    qreal fromY() const;
    void setFromY(qreal y);

    qreal toX() const;
    void setToX(qreal x);

    qreal toY() const;
    void setToY(qreal y);

    Relation fromXType() const;
    void setFromXType(Relation type);

    Relation fromYType() const;
    void setFromYType(Relation type);

    Relation toXType() const;
    void setToXType(Relation type);

    Relation toYType() const;
    void setToYType(Relation type);

Q_SIGNALS:
    void fromXChanged();
    void fromYChanged();
    void toXChanged();
    void toYChanged();
    void fromXTypeChanged();
    void fromYTypeChanged();
    void toXTypeChanged();
    void toYTypeChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    qreal m_fromX;
    qreal m_fromY;
    qreal m_toX;
    qreal m_toY;
    Relation m_fromXType;
    Relation m_fromYType;
    Relation m_toXType;
    Relation m_toYType;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTRANSLATEANIMATION_P_H
