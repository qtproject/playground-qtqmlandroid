#ifndef QTQMLANDROIDCARDVIEW_P_H
#define QTQMLANDROIDCARDVIEW_P_H

#include "qtqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidCardView : public QtQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtQmlAndroidCardView(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCARDVIEW_P_H
