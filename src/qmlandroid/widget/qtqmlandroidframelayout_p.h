#ifndef QQMLANDROIDFRAMELAYOUT_P_H
#define QQMLANDROIDFRAMELAYOUT_P_H

#include "qtqmlandroidviewgroup_p.h"
#include "qtqmlandroidframelayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidFrameLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QQmlAndroidFrameLayout(QQmlAndroidView *parent = 0);

    static QQmlAndroidFrameLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidFrameLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDFRAMELAYOUT_P_H
