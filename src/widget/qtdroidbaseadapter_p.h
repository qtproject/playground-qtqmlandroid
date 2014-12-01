#ifndef QTDROIDBASEADAPTER_P_H
#define QTDROIDBASEADAPTER_P_H

#include "qtdroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtDroidBaseAdapter : public QtDroidObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit QtDroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();

protected:
    virtual QAndroidJniObject construct(jobject context) = 0;
    virtual void inflate(jobject context) = 0;

private:
    friend class QtDroidAdapterView;
};

QT_END_NAMESPACE

#endif // QTDROIDBASEADAPTER_P_H
