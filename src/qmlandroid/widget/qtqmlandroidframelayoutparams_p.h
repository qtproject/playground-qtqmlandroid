#ifndef QTQMLANDROIDFRAMELAYOUTPARAMS_P_H
#define QTQMLANDROIDFRAMELAYOUTPARAMS_P_H

#include "qtqmlandroidmarginlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidFrameLayoutParams : public QtQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtQmlAndroidFrameLayoutParams(QtQmlAndroidView *view);

    int gravity() const;
    void setGravity(int gravity);

Q_SIGNALS:
    void gravityChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtQmlAndroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDFRAMELAYOUTPARAMS_P_H
