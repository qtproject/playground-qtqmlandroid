#ifndef QTDROIDCHECKBOX_P_H
#define QTDROIDCHECKBOX_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtDroidCheckBox : public QtDroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtDroidCheckBox(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDCHECKBOX_P_H
