#ifndef QQMLANDROIDDRAWABLE_P_H
#define QQMLANDROIDDRAWABLE_P_H

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

#include "qqmlandroidobject_p.h"

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

#endif // QQMLANDROIDDRAWABLE_P_H
