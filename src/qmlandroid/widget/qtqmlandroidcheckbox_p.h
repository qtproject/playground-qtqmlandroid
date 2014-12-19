#ifndef QTQMLANDROIDCHECKBOX_P_H
#define QTQMLANDROIDCHECKBOX_P_H

#include "qtqmlandroidcompoundbutton_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidCheckBox : public QQmlAndroidCompoundButton
{
    Q_OBJECT

public:
    explicit QQmlAndroidCheckBox(QQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCHECKBOX_P_H
