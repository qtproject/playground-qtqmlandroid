#ifndef QTDROIDVIEWGROUP_P_H
#define QTDROIDVIEWGROUP_P_H

#include "qtdroidview_p.h"
#include <QtQml/qqml.h>

QT_BEGIN_NAMESPACE

class QtDroidViewGroup : public QtDroidView
{
    Q_OBJECT

public:
    explicit QtDroidViewGroup(QObject *parent = 0);

    static QtDroidLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidViewGroup, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDVIEWGROUP_P_H
