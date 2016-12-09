#ifndef QQMLANDROIDLINEARLAYOUTPARAMS_P_H
#define QQMLANDROIDLINEARLAYOUTPARAMS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQmlAndroid/private/qqmlandroidmarginlayoutparams_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidLinearLayoutParams : public QQmlAndroidMarginLayoutParams
{
    Q_OBJECT
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)
    Q_PROPERTY(qreal weight READ weight WRITE setWeight NOTIFY weightChanged)

public:
    explicit QQmlAndroidLinearLayoutParams(QQmlAndroidView *view);

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
    QQmlAndroidOptional<int> m_gravity;
    QQmlAndroidOptional<qreal> m_weight;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDLINEARLAYOUTPARAMS_P_H
