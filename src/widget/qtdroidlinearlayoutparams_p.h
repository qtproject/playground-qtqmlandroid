#ifndef QTDROIDLINEARLAYOUTPARAMS_P_H
#define QTDROIDLINEARLAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidLinearLayoutParams : public QtDroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    explicit QtDroidLinearLayoutParams(QtDroidView *view);

    int gravity() const;
    void setGravity(int gravity);

    qreal weight() const;
    void setWeight(qreal weight);

Q_SIGNALS:
    void gravityChanged();
    void weightChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void applyParams(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtDroidOptional<int> m_gravity;
    QtDroidOptional<qreal> m_weight;
};

QT_END_NAMESPACE

#endif // QTDROIDLINEARLAYOUTPARAMS_P_H
