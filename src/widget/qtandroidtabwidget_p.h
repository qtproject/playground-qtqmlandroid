#ifndef QTANDROIDTABWIDGET_P_H
#define QTANDROIDTABWIDGET_P_H

#include "qtandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidTabWidget : public QtAndroidLinearLayout
{
    Q_OBJECT

public:
    explicit QtAndroidTabWidget(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDTABWIDGET_P_H
