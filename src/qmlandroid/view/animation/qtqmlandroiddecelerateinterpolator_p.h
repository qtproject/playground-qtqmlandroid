#ifndef QTQMLANDROIDDECELERATEINTERPOLATOR_P_H
#define QTQMLANDROIDDECELERATEINTERPOLATOR_P_H

#include "qtqmlandroidinterpolator_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidDecelerateInterpolator : public QtQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)

public:
    explicit QtQmlAndroidDecelerateInterpolator(QObject *parent = 0);

    qreal factor() const;
    void setFactor(qreal factor);

Q_SIGNALS:
    void factorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<qreal> m_factor;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDDECELERATEINTERPOLATOR_P_H
