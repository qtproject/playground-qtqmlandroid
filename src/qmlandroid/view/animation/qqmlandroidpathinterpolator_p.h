#ifndef QQMLANDROIDAPATHINTERPOLATOR_P_H
#define QQMLANDROIDAPATHINTERPOLATOR_P_H

#include "qqmlandroidinterpolator_p.h"
#include "qqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidPathInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal controlX READ controlX WRITE setControlX NOTIFY controlXChanged)
    Q_PROPERTY(qreal controlY READ controlY WRITE setControlY NOTIFY controlYChanged)
    Q_PROPERTY(qreal controlX2 READ controlX2 WRITE setControlX2 NOTIFY controlX2Changed)
    Q_PROPERTY(qreal controlY2 READ controlY2 WRITE setControlY2 NOTIFY controlY2Changed)

public:
    explicit QQmlAndroidPathInterpolator(QObject *parent = 0);

    qreal controlX() const;
    void setControlX(qreal x);

    qreal controlY() const;
    void setControlY(qreal y);

    qreal controlX2() const;
    void setControlX2(qreal x);

    qreal controlY2() const;
    void setControlY2(qreal y);

Q_SIGNALS:
    void controlXChanged();
    void controlYChanged();
    void controlX2Changed();
    void controlY2Changed();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
    QQmlAndroidOptional<qreal> m_controlX;
    QQmlAndroidOptional<qreal> m_controlY;
    QQmlAndroidOptional<qreal> m_controlX2;
    QQmlAndroidOptional<qreal> m_controlY2;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDAPATHINTERPOLATOR_P_H
