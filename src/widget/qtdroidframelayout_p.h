#ifndef QTDROIDFRAMELAYOUT_P_H
#define QTDROIDFRAMELAYOUT_P_H

#include "qtdroidviewgroup_p.h"

QT_BEGIN_NAMESPACE

class QtDroidFrameLayout : public QtDroidViewGroup
{
    Q_OBJECT

public:
    explicit QtDroidFrameLayout(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDFRAMELAYOUT_P_H
