#ifndef QTDROIDPOPUPMENU_P_H
#define QTDROIDPOPUPMENU_P_H

#include "qtdroidobject_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtDroidView;
class QtDroidMenuItem;

class QtDroidPopupMenu : public QtDroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtDroidView *anchor READ anchor WRITE setAnchor NOTIFY anchorChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtDroidPopupMenu(QObject *parent = 0);

    QList<QtDroidMenuItem *> items() const;

    QtDroidView *anchor() const;
    void setAnchor(QtDroidView *anchor);

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
    QtDroidView *m_anchor;
    QtDroidOptional<int> m_gravity;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTDROIDPOPUPMENU_P_H
