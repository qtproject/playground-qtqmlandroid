#ifndef QQMLANDROIDTABWIDGET_P_H
#define QQMLANDROIDTABWIDGET_P_H

#include "qtqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidTabWidget : public QQmlAndroidLinearLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidTabWidget(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTABWIDGET_P_H
