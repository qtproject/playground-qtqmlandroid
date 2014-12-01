#ifndef QTDROIDARRAYADAPTER_P_H
#define QTDROIDARRAYADAPTER_P_H

#include "qtdroidbaseadapter_p.h"
#include <QtCore/qstring.h>

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

public Q_SLOTS:
    void clear() Q_DECL_OVERRIDE;

Q_SIGNALS:
    void arrayChanged();

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;

private:
    QStringList m_array;
};

QT_END_NAMESPACE

#endif // QTDROIDARRAYADAPTER_P_H
