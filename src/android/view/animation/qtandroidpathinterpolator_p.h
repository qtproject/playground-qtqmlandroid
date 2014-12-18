#ifndef QTANDROIDAPATHINTERPOLATOR_P_H
#define QTANDROIDAPATHINTERPOLATOR_P_H

#include "qtandroidinterpolator_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidPathInterpolator : public QtAndroidInterpolator
{
    Q_OBJECT
    Q_PROPERTY(qreal controlX READ controlX WRITE setControlX NOTIFY controlXChanged)
    Q_PROPERTY(qreal controlY READ controlY WRITE setControlY NOTIFY controlYChanged)
    Q_PROPERTY(qreal controlX2 READ controlX2 WRITE setControlX2 NOTIFY controlX2Changed)
    Q_PROPERTY(qreal controlY2 READ controlY2 WRITE setControlY2 NOTIFY controlY2Changed)

public:
    explicit QtAndroidPathInterpolator(QObject *parent = 0);

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
    QtAndroidOptional<qreal> m_controlX;
    QtAndroidOptional<qreal> m_controlY;
    QtAndroidOptional<qreal> m_controlX2;
    QtAndroidOptional<qreal> m_controlY2;
};

QT_END_NAMESPACE

#endif // QTANDROIDAPATHINTERPOLATOR_P_H
