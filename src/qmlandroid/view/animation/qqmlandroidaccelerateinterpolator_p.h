#ifndef QQMLANDROIDACCELERATEINTERPOLATOR_P_H
#define QQMLANDROIDACCELERATEINTERPOLATOR_P_H

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

class QQmlAndroidAccelerateInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal factor READ factor WRITE setFactor NOTIFY factorChanged)

public:
    explicit QQmlAndroidAccelerateInterpolator(QObject *parent = 0);

    qreal factor() const;
    void setFactor(qreal factor);

Q_SIGNALS:
    void factorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_factor;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACCELERATEINTERPOLATOR_P_H
