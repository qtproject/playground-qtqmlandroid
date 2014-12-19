#ifndef QTQMLANDROIDLISTVIEW_P_H
#define QTQMLANDROIDLISTVIEW_P_H

#include "qtqmlandroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidListView : public QtQmlAndroidAdapterView // TODO: AbsListView
{
    Q_OBJECT

public:
    explicit QtQmlAndroidListView(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDLISTVIEW_P_H
