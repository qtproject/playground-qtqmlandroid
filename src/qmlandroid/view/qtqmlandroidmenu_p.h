#ifndef QTQMLANDROIDMENU_P_H
#define QTQMLANDROIDMENU_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidMenuItem;

class QtQmlAndroidMenu : public QtQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QtQmlAndroidMenu(QObject *parent = 0);

    QList<QtQmlAndroidMenuItem *> items() const;

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDMENU_P_H
