#ifndef QTANDROIDSWITCH_P_H
#define QTANDROIDSWITCH_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSwitch : public QtAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtAndroidSwitch(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDSWITCH_P_H
