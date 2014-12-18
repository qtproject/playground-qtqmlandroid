#ifndef QTANDROIDOVERSHOOTINTERPOLATOR_P_H
#define QTANDROIDOVERSHOOTINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidOvershootInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)

public:
    explicit QtAndroidOvershootInterpolator(QObject *parent = 0);

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

#endif // QTANDROIDOVERSHOOTINTERPOLATOR_P_H
