#ifndef QTANDROIDSPINNER_P_H
#define QTANDROIDSPINNER_P_H

#include "qtandroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSpinner : public QtAndroidAdapterView // TODO: AbsSpinner
{
    Q_OBJECT

public:
    explicit QtAndroidSpinner(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDSPINNER_P_H
