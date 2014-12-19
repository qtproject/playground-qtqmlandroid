#ifndef QTQMLANDROIDSPACE_P_H
#define QTQMLANDROIDSPACE_P_H

#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidSpace : public QtQmlAndroidView
{
    Q_OBJECT

public:
    explicit QtQmlAndroidSpace(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDSPACE_P_H
