#ifndef QTDROIDMENUITEM_P_H
#define QTDROIDMENUITEM_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QtDroidMenuItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    explicit QtDroidMenuItem(QObject *parent = 0);

    QString title() const;
    void setTitle(const QString &title);

Q_SIGNALS:
    void titleChanged();

private:
    QString m_title;
};

QT_END_NAMESPACE

#endif // QTDROIDMENUITEM_P_H
