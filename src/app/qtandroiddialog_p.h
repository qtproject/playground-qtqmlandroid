#ifndef QTANDROIDDIALOG_P_H
#define QTANDROIDDIALOG_P_H

#include "qtandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidDialog : public QtAndroidContextual
{
    Q_OBJECT

public:
    explicit QtAndroidDialog(QObject *parent = 0);

public Q_SLOTS:
    void cancel();
    void dismiss();
    void hide();
    void show();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QTANDROIDDIALOG_P_H
