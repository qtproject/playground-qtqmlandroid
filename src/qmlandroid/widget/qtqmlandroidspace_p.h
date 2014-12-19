#ifndef QQMLANDROIDSPACE_P_H
#define QQMLANDROIDSPACE_P_H

#include "qtqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidSpace : public QQmlAndroidView
{
    Q_OBJECT

public:
    explicit QQmlAndroidSpace(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSPACE_P_H
