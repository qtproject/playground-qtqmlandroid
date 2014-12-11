#ifndef QTANDROIDRADIOBUTTON_P_H
#define QTANDROIDRADIOBUTTON_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidRadioButton : public QtAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtAndroidRadioButton(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDRADIOBUTTON_P_H
