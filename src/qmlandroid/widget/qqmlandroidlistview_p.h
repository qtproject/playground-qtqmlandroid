#ifndef QQMLANDROIDLISTVIEW_P_H
#define QQMLANDROIDLISTVIEW_P_H

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

#include "qqmlandroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidListView : public QQmlAndroidAdapterView // TODO: AbsListView
{
    Q_OBJECT

public:
    explicit QQmlAndroidListView(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDLISTVIEW_P_H
