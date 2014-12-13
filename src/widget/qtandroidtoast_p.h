#ifndef QTANDROIDTOAST_P_H
#define QTANDROIDTOAST_P_H

#include "qtandroidobject_p.h"
#include "qtandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;

class QtAndroidToast : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtAndroidToast(QObject *parent = 0);

    QString text() const;
    void setText(const QString &text);

    int gravity() const;
    void setGravity(int gravity);

public Q_SLOTS:
    void show();
    void cancel();

Q_SIGNALS:
    void textChanged();
    void gravityChanged();

private:
    QString m_text;
    QtAndroidOptional<int> m_gravity;
};

QT_END_NAMESPACE

#endif // QTANDROIDTOAST_P_H
