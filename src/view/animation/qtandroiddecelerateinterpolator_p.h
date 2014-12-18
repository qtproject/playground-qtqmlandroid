#ifndef QTANDROIDDECELERATEINTERPOLATOR_P_H
#define QTANDROIDDECELERATEINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDecelerateInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)

public:
    explicit QtAndroidDecelerateInterpolator(QObject *parent = 0);

    qreal factor() const;
    void setFactor(qreal factor);

Q_SIGNALS:
    void factorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<qreal> m_factor;
};

QT_END_NAMESPACE

#endif // QTANDROIDDECELERATEINTERPOLATOR_P_H
