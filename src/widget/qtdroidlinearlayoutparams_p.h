#ifndef QTDROIDLINEARLAYOUTPARAMS_P_H
#define QTDROIDLINEARLAYOUTPARAMS_P_H

#include "qtdroidlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidLinearLayout;

class QtDroidLinearLayoutParams : public QtDroidLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    explicit QtDroidLinearLayoutParams(QtDroidLinearLayout *layout);

    int gravity() const;
    void setGravity(int gravity);

    qreal weight() const;
    void setWeight(qreal weight);

Q_SIGNALS:
    void gravityChanged();
    void weightChanged();

protected:
    virtual void applyParams(QtDroidView *view);

private:
    QtDroidOptional<int> m_gravity;
    QtDroidOptional<qreal> m_weight;
};

QT_END_NAMESPACE

#endif // QTDROIDLINEARLAYOUTPARAMS_P_H
