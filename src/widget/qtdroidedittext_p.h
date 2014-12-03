#ifndef QTDROIDEDITTEXT_P_H
#define QTDROIDEDITTEXT_P_H

#include "qtdroidtextview_p.h"

QT_BEGIN_NAMESPACE

class QtDroidEditText : public QtDroidTextView
{
    Q_OBJECT

public:
    explicit QtDroidEditText(QtDroidView *parent = 0);

protected:
    QAndroidJniObject construct(jobject context) Q_DECL_OVERRIDE;
    void inflate(jobject context) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTDROIDEDITTEXT_P_H
