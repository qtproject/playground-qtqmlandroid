#ifndef QQMLANDROIDACTIONBARDRAWERTOGGLE_P_H
#define QQMLANDROIDACTIONBARDRAWERTOGGLE_P_H

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

class QQmlAndroidActionBarDrawerToggle : public QQmlAndroidObject
{
    Q_OBJECT

public:
    explicit QQmlAndroidActionBarDrawerToggle(QObject *parent = 0);

    void onCreate(const QAndroidJniObject &activity, const QAndroidJniObject &drawer);
};

QT_END_NAMESPACE

#endif // QQMLANDROIDACTIONBARDRAWERTOGGLE_P_H
