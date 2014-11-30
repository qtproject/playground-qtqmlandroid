#ifndef QTDROIDSWITCH_P_H
#define QTDROIDSWITCH_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtDroidSwitch : public QtDroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtDroidSwitch(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSWITCH_P_H
