#ifndef QTDROIDTABWIDGET_P_H
#define QTDROIDTABWIDGET_P_H

#include "qtdroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidTabWidget : public QtDroidLinearLayout
{
    Q_OBJECT

public:
    explicit QtDroidTabWidget(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDTABWIDGET_P_H
