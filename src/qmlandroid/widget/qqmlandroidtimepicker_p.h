#ifndef QQMLANDROIDTIMEPICKER_P_H
#define QQMLANDROIDTIMEPICKER_P_H

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

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidTimePicker : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidTimePicker(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDTIMEPICKER_P_H
