#ifndef QTANDROIDANTICIPATEINTERPOLATOR_P_H
#define QTANDROIDANTICIPATEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAnticipateInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)

public:
    explicit QtAndroidAnticipateInterpolator(QObject *parent = 0);

    qreal tension() const;
    void setTension(qreal tension);

Q_SIGNALS:
    void tensionChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<qreal> m_tension;
};

QT_END_NAMESPACE

#endif // QTANDROIDANTICIPATEINTERPOLATOR_P_H
