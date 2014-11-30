#ifndef QTDROIDSCROLLVIEW_P_H
#define QTDROIDSCROLLVIEW_P_H

#include "qtdroidframelayout_p.h"

QT_BEGIN_NAMESPACE

class QtDroidScrollView : public QtDroidFrameLayout
{
    Q_OBJECT

public:
    explicit QtDroidScrollView(QObject *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDSCROLLVIEW_P_H
