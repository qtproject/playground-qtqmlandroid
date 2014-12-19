#ifndef QQMLANDROIDRADIOBUTTON_P_H
#define QQMLANDROIDRADIOBUTTON_P_H

#include "qtqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidRadioButton : public QQmlAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QQmlAndroidRadioButton(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QQMLANDROIDRADIOBUTTON_P_H
