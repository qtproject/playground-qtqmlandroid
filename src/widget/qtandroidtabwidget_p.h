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
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDTABWIDGET_P_H
