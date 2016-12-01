#ifndef QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
#define QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H

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

#include "qtqmlandroidglobal_p.h"
#include "qqmlandroidoptional_p.h"
#include "qqmlandroidinterpolator_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidAccelerateDecelerateInterpolator : public QQmlAndroidInterpolator
{
    Q_OBJECT

public:
    explicit QQmlAndroidAccelerateDecelerateInterpolator(QObject *parent = 0);

Q_SIGNALS:

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;

private:
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACCELERATEDECELERATEINTERPOLATOR_P_H
