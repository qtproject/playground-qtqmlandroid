#ifndef QTANDROIDBASEADAPTER_P_H
#define QTANDROIDBASEADAPTER_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidContext;

class QtAndroidBaseAdapter : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(QtAndroidContext *context READ context NOTIFY contextChanged)

public:
    explicit QtAndroidBaseAdapter(QObject *parent = 0);

    virtual int count() const = 0;

    QAndroidJniObject ctx() const;
    QtAndroidContext *context() const;
    void setContext(QtAndroidContext *context);

public Q_SLOTS:
    virtual void clear() = 0;

Q_SIGNALS:
    void countChanged();
    void contextChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QtAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QTANDROIDBASEADAPTER_P_H
