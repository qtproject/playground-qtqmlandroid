#ifndef QQMLANDROIDBUTTON_P_H
#define QQMLANDROIDBUTTON_P_H

#include "qtqmlandroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidButton : public QQmlAndroidTextView
{
    Q_OBJECT

public:
    explicit QQmlAndroidButton(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDBUTTON_P_H
