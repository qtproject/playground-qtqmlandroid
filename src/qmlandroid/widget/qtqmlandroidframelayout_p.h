#ifndef QTQMLANDROIDFRAMELAYOUT_P_H
#define QTQMLANDROIDFRAMELAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidframelayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidFrameLayout : public QtQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QtQmlAndroidFrameLayout(QtQmlAndroidView *parent = 0);

    static QtQmlAndroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtQmlAndroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTQMLANDROIDFRAMELAYOUT_P_H
