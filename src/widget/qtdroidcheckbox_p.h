#ifndef QTDROIDCHECKBOX_P_H
#define QTDROIDCHECKBOX_P_H

#include "qtdroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtDroidCheckBox : public QtDroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtDroidCheckBox(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDCHECKBOX_P_H
