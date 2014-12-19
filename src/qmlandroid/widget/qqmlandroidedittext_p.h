#ifndef QQMLANDROIDEDITTEXT_P_H
#define QQMLANDROIDEDITTEXT_P_H

#include "qqmlandroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidEditText : public QQmlAndroidTextView
{
    Q_OBJECT

public:
    explicit QQmlAndroidEditText(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDEDITTEXT_P_H
