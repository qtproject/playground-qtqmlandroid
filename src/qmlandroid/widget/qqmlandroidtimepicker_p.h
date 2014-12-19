#ifndef QQMLANDROIDTIMEPICKER_P_H
#define QQMLANDROIDTIMEPICKER_P_H

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidTimePicker : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidTimePicker(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTIMEPICKER_P_H
