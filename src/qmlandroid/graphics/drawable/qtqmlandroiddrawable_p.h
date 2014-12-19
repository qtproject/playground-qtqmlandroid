#ifndef QTQMLANDROIDDRAWABLE_P_H
#define QTQMLANDROIDDRAWABLE_P_H

#include "qtqmlandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDrawable : public QQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QQmlAndroidDrawable(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDDRAWABLE_P_H
