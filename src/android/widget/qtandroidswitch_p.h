#ifndef QTANDROIDSWITCH_P_H
#define QTANDROIDSWITCH_P_H

#include "qtandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSwitch : public QtAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtAndroidSwitch(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDSWITCH_P_H
