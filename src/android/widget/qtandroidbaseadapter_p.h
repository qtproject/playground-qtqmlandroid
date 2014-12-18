#ifndef QTANDROIDBASEADAPTER_P_H
#define QTANDROIDBASEADAPTER_P_H

#include "qtandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidBaseAdapter : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit QtAndroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDBASEADAPTER_P_H
