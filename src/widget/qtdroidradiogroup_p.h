#ifndef QTDROIDRADIOGROUP_P_H
#define QTDROIDRADIOGROUP_P_H

#include "qtdroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidRadioGroup : public QtDroidLinearLayout
{
    Q_OBJECT

public:
    explicit QtDroidRadioGroup(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDRADIOGROUP_P_H
