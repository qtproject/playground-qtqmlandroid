#ifndef QTANDROIDMENU_P_H
#define QTANDROIDMENU_P_H

#include "qtandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidMenuItem;

class QtAndroidMenu : public QtAndroidContextual
{
    Q_OBJECT

public:
    explicit QtAndroidMenu(QObject *parent = 0);

    QList<QtAndroidMenuItem *> items() const;

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

private:
    friend class QtAndroidActivity;
};

QT_END_NAMESPACE

#endif // QTANDROIDMENU_P_H
