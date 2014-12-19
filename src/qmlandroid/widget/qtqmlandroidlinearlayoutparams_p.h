#ifndef QTQMLANDROIDLINEARLAYOUTPARAMS_P_H
#define QTQMLANDROIDLINEARLAYOUTPARAMS_P_H

#include "qtqmlandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidLinearLayoutParams : public QtQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    explicit QtQmlAndroidLinearLayoutParams(QtQmlAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

    qreal weight() const;
    void setWeight(qreal weight);

Q_SIGNALS:
    void gravityChanged();
    void weightChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<int> m_gravity;
    QtQmlAndroidOptional<qreal> m_weight;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDLINEARLAYOUTPARAMS_P_H
