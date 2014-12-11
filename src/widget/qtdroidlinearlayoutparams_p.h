#ifndef QTANDROIDLINEARLAYOUTPARAMS_P_H
#define QTANDROIDLINEARLAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidLinearLayoutParams : public QtAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    explicit QtAndroidLinearLayoutParams(QtAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

    qreal weight() const;
    void setWeight(qreal weight);

Q_SIGNALS:
    void gravityChanged();
    void weightChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<int> m_gravity;
    QtAndroidOptional<qreal> m_weight;
};

QT_END_NAMESPACE

#endif // QTANDROIDLINEARLAYOUTPARAMS_P_H
