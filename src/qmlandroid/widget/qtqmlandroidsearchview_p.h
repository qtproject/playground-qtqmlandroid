#ifndef QQMLANDROIDSEARCHVIEW_P_H
#define QQMLANDROIDSEARCHVIEW_P_H

#include "qtqmlandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidSearchView : public QQmlAndroidLinearLayout
{
    Q_OBJECT

public:
    explicit QQmlAndroidSearchView(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDSEARCHVIEW_P_H
