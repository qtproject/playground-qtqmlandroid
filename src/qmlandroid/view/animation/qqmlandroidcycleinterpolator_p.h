#ifndef QQMLANDROIDCYCLEINTERPOLATOR_P_H
#define QQMLANDROIDCYCLEINTERPOLATOR_P_H

#include "qqmlandroidinterpolator_p.h"
#include "qqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidCycleInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal cycles READ cycles WRITE setCycles NOTIFY cyclesChanged)

public:
    explicit QQmlAndroidCycleInterpolator(QObject *parent = 0);

    qreal cycles() const;
    void setCycles(qreal cycles);

Q_SIGNALS:
    void cyclesChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_cycles;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCYCLEINTERPOLATOR_P_H
