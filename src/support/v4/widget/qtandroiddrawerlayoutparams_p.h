#ifndef QTANDROIDDRAWERLAYOUTPARAMS_P_H
#define QTANDROIDDRAWERLAYOUTPARAMS_P_H

#include "qtandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDrawerLayoutParams : public QtAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged) // TODO Gravity

public:
    explicit QtAndroidDrawerLayoutParams(QtAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject onConstruct() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &params) Q_DECL_OVERRIDE;

private:
    int m_gravity;
};

QT_END_NAMESPACE

#endif // QTANDROIDDRAWERLAYOUTPARAMS_P_H
