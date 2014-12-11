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

    void setup(QtAndroidAdapterView *view) Q_DECL_OVERRIDE;

public Q_SLOTS:
    void clear() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void arrayChanged();

private:
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QTANDROIDARRAYADAPTER_P_H
