#ifndef QTANDROIDMENUITEM_P_H
#define QTANDROIDMENUITEM_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QtAndroidMenuItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    explicit QtAndroidMenuItem(QObject *parent = 0);

    QString title() const;
    void setTitle(const QString &title);

Q_SIGNALS:
    void titleChanged();

private:
    QString m_title;
};

QT_END_NAMESPACE

#endif // QTANDROIDMENUITEM_P_H
