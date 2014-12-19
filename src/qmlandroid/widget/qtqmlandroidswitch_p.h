#ifndef QTQMLANDROIDSWITCH_P_H
#define QTQMLANDROIDSWITCH_P_H

#include "qtqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidSwitch : public QtQmlAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtQmlAndroidSwitch(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDSWITCH_P_H
