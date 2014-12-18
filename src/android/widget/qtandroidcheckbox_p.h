#ifndef QTANDROIDCHECKBOX_P_H
#define QTANDROIDCHECKBOX_P_H

#include "qtandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidCheckBox : public QtAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QtAndroidCheckBox(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDCHECKBOX_P_H
