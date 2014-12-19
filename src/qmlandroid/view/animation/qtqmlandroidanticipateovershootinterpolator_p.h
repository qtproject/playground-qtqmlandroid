#ifndef QTQMLANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H
#define QTQMLANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidAnticipateOvershootInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)
    Q_PROPERTY(qreal extraTension READ extraTension WRITE setExtraTension NOTIFY extraTensionChanged)

public:
    explicit QQmlAndroidAnticipateOvershootInterpolator(QObject *parent = 0);

    qreal tension() const;
    void setTension(qreal tension);

    qreal extraTension() const;
    void setExtraTension(qreal tension);

Q_SIGNALS:
    void tensionChanged();
    void extraTensionChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_tension;
    QQmlAndroidOptional<qreal> m_extraTension;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H
