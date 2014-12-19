#ifndef QTQMLANDROIDDATEPICKER_P_H
#define QTQMLANDROIDDATEPICKER_P_H

#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDatePicker : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidDatePicker(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDDATEPICKER_P_H
