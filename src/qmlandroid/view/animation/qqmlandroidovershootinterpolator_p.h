#ifndef QQMLANDROIDOVERSHOOTINTERPOLATOR_P_H
#define QQMLANDROIDOVERSHOOTINTERPOLATOR_P_H

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

class QQmlAndroidOvershootInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal tension READ tension WRITE setTension NOTIFY tensionChanged)

public:
    explicit QQmlAndroidOvershootInterpolator(QObject *parent = 0);

    qreal tension() const;
    void setTension(qreal tension);

Q_SIGNALS:
    void tensionChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_tension;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDOVERSHOOTINTERPOLATOR_P_H
