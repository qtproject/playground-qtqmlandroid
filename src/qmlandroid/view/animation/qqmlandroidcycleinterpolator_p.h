#ifndef QQMLANDROIDCYCLEINTERPOLATOR_P_H
#define QQMLANDROIDCYCLEINTERPOLATOR_P_H

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

#include <QtQmlAndroid/private/qqmlandroidinterpolator_p.h>
#include <QtQmlAndroid/private/qqmlandroidoptional_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidCycleInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal cycles READ cycles WRITE setCycles NOTIFY cyclesChanged)

public:
    explicit QQmlAndroidCycleInterpolator(QObject *parent = 0);

    qreal cycles() const;
    void setCycles(qreal cycles);

Q_SIGNALS:
    void cyclesChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_cycles;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCYCLEINTERPOLATOR_P_H
