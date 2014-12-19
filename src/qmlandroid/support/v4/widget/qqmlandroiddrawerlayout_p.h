#ifndef QQMLANDROIDDRAWERLAYOUT_P_H
#define QQMLANDROIDDRAWERLAYOUT_P_H

#include "qqmlandroidviewgroup_p.h"
#include "qqmlandroiddrawerlayoutparams_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDrawerLayout : public QQmlAndroidViewGroup
{
    Q_OBJECT

public:
    explicit QQmlAndroidDrawerLayout(QQmlAndroidView *parent = 0);

    static QQmlAndroidDrawerLayoutParams *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    void closeDrawers();
    void closeDrawer(int gravity);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidDrawerLayout, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDDRAWERLAYOUT_P_H
