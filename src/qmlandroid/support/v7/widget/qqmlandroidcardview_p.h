#ifndef QQMLANDROIDCARDVIEW_P_H
#define QQMLANDROIDCARDVIEW_P_H

#include "qqmlandroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidCardView : public QQmlAndroidFrameLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidCardView(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDCARDVIEW_P_H
