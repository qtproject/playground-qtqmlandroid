#ifndef QTANDROIDSEARCHVIEW_P_H
#define QTANDROIDSEARCHVIEW_P_H

#include "qtandroidlinearlayout_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidSearchView : public QtAndroidLinearLayout
{
    Q_OBJECT

public:
    explicit QtAndroidSearchView(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDSEARCHVIEW_P_H
