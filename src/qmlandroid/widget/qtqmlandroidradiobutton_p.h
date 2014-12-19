#ifndef QTQMLANDROIDRADIOBUTTON_P_H
#define QTQMLANDROIDRADIOBUTTON_P_H

#include "qtqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidRadioButton : public QtQmlAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtQmlAndroidRadioButton(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDRADIOBUTTON_P_H
