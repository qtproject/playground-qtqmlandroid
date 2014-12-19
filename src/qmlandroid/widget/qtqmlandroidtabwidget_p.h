#ifndef QTQMLANDROIDTABWIDGET_P_H
#define QTQMLANDROIDTABWIDGET_P_H

#include "qtqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidTabWidget : public QtQmlAndroidLinearLayout
{
    Q_OBJECT

public:
    explicit QtQmlAndroidTabWidget(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDTABWIDGET_P_H
