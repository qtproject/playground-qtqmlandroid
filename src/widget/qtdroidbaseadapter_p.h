#ifndef QTANDROIDBASEADAPTER_P_H
#define QTANDROIDBASEADAPTER_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QtAndroidAdapterView;

class QtAndroidBaseAdapter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    explicit QtAndroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

    virtual void setup(QtAndroidAdapterView *view) = 0;

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();
};

QT_END_NAMESPACE

#endif // QTANDROIDBASEADAPTER_P_H
