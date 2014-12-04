#ifndef QTDROIDFRAMELAYOUTPARAMS_P_H
#define QTDROIDFRAMELAYOUTPARAMS_P_H

#include "qtdroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidFrameLayoutParams : public QtDroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtDroidFrameLayoutParams(QtDroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    QtDroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QTDROIDFRAMELAYOUTPARAMS_P_H
