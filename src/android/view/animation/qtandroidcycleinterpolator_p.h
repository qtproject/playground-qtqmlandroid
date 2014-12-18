#ifndef QTANDROIDCYCLEINTERPOLATOR_P_H
#define QTANDROIDCYCLEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidCycleInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal cycles READ cycles WRITE setCycles NOTIFY cyclesChanged)

public:
    explicit QtAndroidCycleInterpolator(QObject *parent = 0);

    qreal cycles() const;
    void setCycles(qreal cycles);

Q_SIGNALS:
    void cyclesChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<qreal> m_cycles;
};

QT_END_NAMESPACE

#endif // QTANDROIDCYCLEINTERPOLATOR_P_H
