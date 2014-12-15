#ifndef QTANDROIDRECYCLERADAPTER_P_H
#define QTANDROIDRECYCLERADAPTER_P_H

#include "qtandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRecyclerAdapter : public QtAndroidContextual
{
    Q_OBJECT
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit QtAndroidRecyclerAdapter(QObject *parent = 0);

    int count() const;
    void setCount(int count);

Q_SIGNALS:
    void countChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    int m_count;
};

QT_END_NAMESPACE

#endif // QTANDROIDRECYCLERADAPTER_P_H
