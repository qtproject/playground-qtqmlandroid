#ifndef QTANDROIDFRAMELAYOUTPARAMS_P_H
#define QTANDROIDFRAMELAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidFrameLayoutParams : public QtAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtAndroidFrameLayoutParams(QtAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtAndroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QTANDROIDFRAMELAYOUTPARAMS_P_H
