#ifndef QTQMLANDROIDPOPUPMENU_P_H
#define QTQMLANDROIDPOPUPMENU_P_H

#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidView;
class QtQmlAndroidMenuItem;

class QtQmlAndroidPopupMenu : public QtQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidView *anchor READ anchor WRITE setAnchor NOTIFY anchorChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtQmlAndroidPopupMenu(QObject *parent = 0);

    QList<QtQmlAndroidMenuItem *> items() const;

    QtQmlAndroidView *anchor() const;
    void setAnchor(QtQmlAndroidView *anchor);

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
    QtQmlAndroidView *m_anchor;
    QtQmlAndroidOptional<int> m_gravity;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDPOPUPMENU_P_H
