#ifndef QTDROIDSCROLLVIEW_P_H
#define QTDROIDSCROLLVIEW_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidScrollView : public QtDroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtDroidScrollView(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSCROLLVIEW_P_H
