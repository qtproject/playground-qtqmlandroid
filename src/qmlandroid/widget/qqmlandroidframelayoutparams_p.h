#ifndef QQMLANDROIDFRAMELAYOUTPARAMS_P_H
#define QQMLANDROIDFRAMELAYOUTPARAMS_P_H

#include "qqmlandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidFrameLayoutParams : public QQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QQmlAndroidFrameLayoutParams(QQmlAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDFRAMELAYOUTPARAMS_P_H
