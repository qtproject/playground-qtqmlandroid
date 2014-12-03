#ifndef QTDROIDSPACE_P_H
#define QTDROIDSPACE_P_H

#include "qtdroidview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidSpace : public QtDroidView
{
    Q_OBJECT

public:
    explicit QtDroidSpace(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSPACE_P_H
