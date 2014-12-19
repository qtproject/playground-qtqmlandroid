#ifndef QTQMLANDROIDCOLORDRAWABLE_P_H
#define QTQMLANDROIDCOLORDRAWABLE_P_H

#include "qtqmlandroiddrawable_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidColorDrawable : public QtQmlAndroidDrawable
{
    Q_OBJECT
    Q_PROPERTY(int color READ color WRITE setColor NOTIFY colorChanged)

public:
    explicit QtQmlAndroidColorDrawable(QObject *parent = 0);
    explicit QtQmlAndroidColorDrawable(int color, QObject *parent = 0);

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

#endif // QTQMLANDROIDCOLORDRAWABLE_P_H
