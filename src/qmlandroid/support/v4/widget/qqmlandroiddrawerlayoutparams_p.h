#ifndef QQMLANDROIDDRAWERLAYOUTPARAMS_P_H
#define QQMLANDROIDDRAWERLAYOUTPARAMS_P_H

#include "qqmlandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDrawerLayoutParams : public QQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged) // TODO Gravity

public:
    explicit QQmlAndroidDrawerLayoutParams(QQmlAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_gravity;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDDRAWERLAYOUTPARAMS_P_H
