#ifndef QTDROIDLISTVIEW_P_H
#define QTDROIDLISTVIEW_P_H

#include "qtdroidadapterview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidListView : public QtDroidAdapterView // TODO: AbsListView
{
    Q_OBJECT

public:
    explicit QtDroidListView(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDLISTVIEW_P_H
