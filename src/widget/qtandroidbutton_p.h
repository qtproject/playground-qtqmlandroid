#ifndef QTANDROIDBUTTON_P_H
#define QTANDROIDBUTTON_P_H

#include "qtandroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidButton : public QtAndroidTextView
{
    Q_OBJECT

public:
    explicit QtAndroidButton(QtAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDBUTTON_P_H
