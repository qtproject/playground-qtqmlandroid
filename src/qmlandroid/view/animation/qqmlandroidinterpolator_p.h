#ifndef QQMLANDROIDINTERPOLATOR_P_H
#define QQMLANDROIDINTERPOLATOR_P_H

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

#include <QtQmlAndroid/private/qqmlandroidobject_p.h>

QT_BEGIN_NAMESPACE

class QQmlAndroidInterpolator : public QQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QQmlAndroidInterpolator(QObject *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDINTERPOLATOR_P_H
