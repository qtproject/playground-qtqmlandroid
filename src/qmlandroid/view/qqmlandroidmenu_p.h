#ifndef QQMLANDROIDMENU_P_H
#define QQMLANDROIDMENU_P_H

#include "qqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidMenuItem;

class QQmlAndroidMenu : public QQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QQmlAndroidMenu(QObject *parent = 0);

    QList<QQmlAndroidMenuItem *> items() const;

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDMENU_P_H
