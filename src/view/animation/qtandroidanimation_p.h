#ifndef QTANDROIDANIMATION_P_H
#define QTANDROIDANIMATION_P_H

#include "qtandroidcontextual_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAnimation : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int resource READ resource WRITE setResource NOTIFY resourceChanged)
    Q_PROPERTY(int repeatCount READ repeatCount WRITE setRepeatCount NOTIFY repeatCountChanged)

public:
    explicit QtAndroidAnimation(QObject *parent = 0);

    int resource() const;
    void setResource(int resource);

    int repeatCount() const;
    void setRepeatCount(int count);

public Q_SLOTS:
    void cancel();
    void start();

Q_SIGNALS:
    void resourceChanged();
    void repeatCountChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_resource;
    QtAndroidOptional<int> m_repeatCount;
};

QT_END_NAMESPACE

#endif // QTANDROIDANIMATION_P_H
