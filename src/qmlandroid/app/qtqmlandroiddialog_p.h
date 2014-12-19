#ifndef QTQMLANDROIDDIALOG_P_H
#define QTQMLANDROIDDIALOG_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidDialog : public QtQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QtQmlAndroidDialog(QObject *parent = 0);

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

#endif // QTQMLANDROIDDIALOG_P_H
