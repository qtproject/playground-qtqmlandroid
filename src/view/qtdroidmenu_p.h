#ifndef QTDROIDMENU_P_H
#define QTDROIDMENU_P_H

#include "qtdroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtDroidMenuItem;

class QtDroidMenu : public QtDroidObject
{
    Q_OBJECT

public:
    explicit QtDroidMenu(QObject *parent = 0);

    QList<QtDroidMenuItem *> items() const;

protected:
    void objectAdded(QObject *object) Q_DECL_OVERRIDE;
    void objectRemoved(QObject *object) Q_DECL_OVERRIDE;

private:
    QList<QtDroidMenuItem *> m_items;
};

QT_END_NAMESPACE

#endif // QTDROIDMENU_P_H
