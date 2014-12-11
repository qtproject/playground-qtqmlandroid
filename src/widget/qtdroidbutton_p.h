#ifndef QTANDROIDBUTTON_P_H
#define QTANDROIDBUTTON_P_H

#include "qtdroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidButton : public QtAndroidTextView
{
    Q_OBJECT

public:
    explicit QtAndroidButton(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject construct() Q_DECL_OVERRIDE;
    void inflate() Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDBUTTON_P_H
