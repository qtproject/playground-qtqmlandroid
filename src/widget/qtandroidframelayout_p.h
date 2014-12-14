#ifndef QTANDROIDFRAMELAYOUT_P_H
#define QTANDROIDFRAMELAYOUT_P_H

#include "qtandroidviewgroup_p.h"
#include "qtandroidframelayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidFrameLayout : public QtAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QtAndroidFrameLayout(QtAndroidView *parent = 0);

    static QtAndroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QtAndroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QTANDROIDFRAMELAYOUT_P_H
