#ifndef QTDROIDRADIOBUTTON_P_H
#define QTDROIDRADIOBUTTON_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtDroidRadioButton : public QtDroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtDroidRadioButton(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDRADIOBUTTON_P_H
