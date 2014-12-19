#ifndef QTQMLANDROIDPOPUPMENU_P_H
#define QTQMLANDROIDPOPUPMENU_P_H

#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidView;
class QQmlAndroidMenuItem;

class QQmlAndroidPopupMenu : public QQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlAndroidView *anchor READ anchor WRITE setAnchor NOTIFY anchorChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QQmlAndroidPopupMenu(QObject *parent = 0);

    QList<QQmlAndroidMenuItem *> items() const;

    QQmlAndroidView *anchor() const;
    void setAnchor(QQmlAndroidView *anchor);

    int gravity() const;
    void setGravity(int gravity);

public Q_SLOTS:
    void show();
    void dismiss();

Q_SIGNALS:
    void anchorChanged();
    void gravityChanged();
    void dismissed();
    void itemClick();

private:
    QQmlAndroidView *m_anchor;
    QQmlAndroidOptional<int> m_gravity;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDPOPUPMENU_P_H
