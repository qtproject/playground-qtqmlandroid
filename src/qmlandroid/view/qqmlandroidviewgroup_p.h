#ifndef QQMLANDROIDVIEWGROUP_P_H
#define QQMLANDROIDVIEWGROUP_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qqmlandroidview_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidViewGroup : public QQmlAndroidView
{
    Q_OBJECT

public:
    explicit QQmlAndroidViewGroup(QQmlAndroidView *parent = 0);

    static QQmlAndroidLayoutParams *qmlAttachedProperties(QObject *object);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;

    void viewChange(ViewChange change, const ViewChangeData &data) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

QML_DECLARE_TYPEINFO(QQmlAndroidViewGroup, QML_HAS_ATTACHED_PROPERTIES)

#endif // QQMLANDROIDVIEWGROUP_P_H
