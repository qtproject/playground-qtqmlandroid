#ifndef QTQMLANDROIDSPINNER_P_H
#define QTQMLANDROIDSPINNER_P_H

#include "qtqmlandroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidSpinner : public QtQmlAndroidAdapterView // TODO: AbsSpinner
{
    Q_OBJECT

public:
    explicit QtQmlAndroidSpinner(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDSPINNER_P_H
