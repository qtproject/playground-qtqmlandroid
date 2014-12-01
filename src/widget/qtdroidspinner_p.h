#ifndef QTDROIDSPINNER_P_H
#define QTDROIDSPINNER_P_H

#include "qtdroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidSpinner : public QtDroidAdapterView // TODO: AbsSpinner
{
    Q_OBJECT

public:
    explicit QtDroidSpinner(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSPINNER_P_H
