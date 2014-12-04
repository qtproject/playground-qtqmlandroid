#ifndef QTDROIDBASEADAPTER_P_H
#define QTDROIDBASEADAPTER_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QtDroidAdapterView;

class QtDroidBaseAdapter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit QtDroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

    virtual void setup(QtDroidAdapterView *view) = 0;

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();
};

QT_END_NAMESPACE

#endif // QTDROIDBASEADAPTER_P_H
