#ifndef QTANDROIDARRAYADAPTER_P_H
#define QTANDROIDARRAYADAPTER_P_H

#include "qtandroidbaseadapter_p.h"
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QtAndroidArrayAdapter : public QtAndroidBaseAdapter
{
    Q_OBJECT
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QtAndroidArrayAdapter(QObject *parent = 0);

    QStringList array() const;
    void setArray(const QStringList &array);

    int count() const Q_DECL_OVERRIDE;
    Q_INVOKABLE QString getItem(int position) const;

public Q_SLOTS:
    void clear() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void arrayChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QTANDROIDARRAYADAPTER_P_H
