#ifndef QTDROIDFRAMELAYOUT_P_H
#define QTDROIDFRAMELAYOUT_P_H

#include "qtdroidviewgroup_p.h"
#include "qtdroidframelayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtDroidFrameLayout : public QtDroidViewGroup
{
    Q_OBJECT

public:
    explicit QtDroidFrameLayout(QtDroidView *parent = 0);

    static QtDroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtDroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTDROIDFRAMELAYOUT_P_H
