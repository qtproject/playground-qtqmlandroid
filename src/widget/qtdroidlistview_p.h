#ifndef QTANDROIDLISTVIEW_P_H
#define QTANDROIDLISTVIEW_P_H

#include "qtdroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidListView : public QtAndroidAdapterView // TODO: AbsListView
{
    Q_OBJECT

public:
    explicit QtAndroidListView(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDLISTVIEW_P_H
