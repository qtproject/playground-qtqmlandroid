#ifndef QTQMLANDROIDEDITTEXT_P_H
#define QTQMLANDROIDEDITTEXT_P_H

#include "qtqmlandroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidEditText : public QtQmlAndroidTextView
{
    Q_OBJECT

public:
    explicit QtQmlAndroidEditText(QtQmlAndroidView *parent = 0);

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject &instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDEDITTEXT_P_H
