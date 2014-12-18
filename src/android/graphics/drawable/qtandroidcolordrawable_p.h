#ifndef QTANDROIDCOLORDRAWABLE_P_H
#define QTANDROIDCOLORDRAWABLE_P_H

#include "qtandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidColorDrawable : public QtAndroidDrawable
{
    Q_OBJECT
    Q_PROPERTY(int color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit QtAndroidColorDrawable(QObject *parent = 0);
    explicit QtAndroidColorDrawable(int color, QObject *parent = 0);

    int color() const;
    void setColor(int color);

Q_SIGNALS:
    void colorChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_color;
};

QT_END_NAMESPACE

#endif // QTANDROIDCOLORDRAWABLE_P_H
