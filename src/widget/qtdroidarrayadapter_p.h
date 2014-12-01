#ifndef QTDROIDARRAYADAPTER_P_H
#define QTDROIDARRAYADAPTER_P_H

#include "qtdroidobject_p.h"
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class QtDroidArrayAdapter : public QtDroidObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(QStringList array READ array WRITE setArray NOTIFY arrayChanged)

public:
    explicit QtDroidArrayAdapter(QObject *parent = 0);

    QStringList array() const;
    void setArray(const QStringList &array);

    int count() const;
    Q_INVOKABLE QString getItem(int position) const;

public Q_SLOTS:
    void clear();

Q_SIGNALS:
    void arrayChanged();
    void countChanged();

protected:
    QAndroidJniObject construct(jobject context);
    void inflate(jobject context);

private:
    QStringList m_array;

    friend class QtDroidAdapterView;
};

QT_END_NAMESPACE

#endif // QTDROIDARRAYADAPTER_P_H
