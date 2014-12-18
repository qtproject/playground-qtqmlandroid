#ifndef QTANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H
#define QTANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAnticipateOvershootInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)
    Q_PROPERTY(qreal extraTension READ extraTension WRITE setExtraTension NOTIFY extraTensionChanged)

public:
    explicit QtAndroidAnticipateOvershootInterpolator(QObject *parent = 0);

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
    QtAndroidOptional<qreal> m_tension;
    QtAndroidOptional<qreal> m_extraTension;
};

QT_END_NAMESPACE

#endif // QTANDROIDANTICIPATEOVERSHOOTINTERPOLATOR_P_H
