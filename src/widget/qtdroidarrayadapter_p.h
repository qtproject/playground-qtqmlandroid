#ifndef QTDROIDARRAYADAPTER_P_H
#define QTDROIDARRAYADAPTER_P_H

#include "qtdroidbaseadapter_p.h"
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QtDroidArrayAdapter : public QtDroidBaseAdapter
{
    Q_OBJECT
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QtDroidArrayAdapter(QObject *parent = 0);

    QStringList array() const;
    void setArray(const QStringList &array);

    int count() const Q_DECL_OVERRIDE;
    Q_INVOKABLE QString getItem(int position) const;

    void setup(QtDroidAdapterView *view) Q_DECL_OVERRIDE;

public Q_SLOTS:
    void clear() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void arrayChanged();

private:
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QTDROIDARRAYADAPTER_P_H
