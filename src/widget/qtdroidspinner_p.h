#ifndef QTDROIDSPINNER_P_H
#define QTDROIDSPINNER_P_H

#include "qtdroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSpinner : public QtAndroidAdapterView // TODO: AbsSpinner
{
    Q_OBJECT

public:
    explicit QtAndroidSpinner(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSPINNER_P_H
