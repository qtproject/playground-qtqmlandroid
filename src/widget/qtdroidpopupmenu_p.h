#ifndef QTANDROIDPOPUPMENU_P_H
#define QTANDROIDPOPUPMENU_P_H

#include "qtdroidobject_p.h"
#include "qtdroidoptional_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidView;
class QtAndroidMenuItem;

class QtAndroidPopupMenu : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidView *anchor READ anchor WRITE setAnchor NOTIFY anchorChanged)
    Q_PROPERTY(int gravity READ gravity WRITE setGravity NOTIFY gravityChanged)

public:
    explicit QtAndroidPopupMenu(QObject *parent = 0);

    QList<QtAndroidMenuItem *> items() const;

    QtAndroidView *anchor() const;
    void setAnchor(QtAndroidView *anchor);

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
    QtAndroidView *m_anchor;
    QtAndroidOptional<int> m_gravity;
    QAndroidJniObject m_listener;
};

QT_END_NAMESPACE

#endif // QTANDROIDPOPUPMENU_P_H
