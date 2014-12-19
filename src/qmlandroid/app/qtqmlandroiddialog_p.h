#ifndef QQMLANDROIDDIALOG_P_H
#define QQMLANDROIDDIALOG_P_H

#include "qtqmlandroidcontextual_p.h"

QT_BEGIN_NAMESPACE

class QQmlAndroidDialog : public QQmlAndroidContextual
{
    Q_OBJECT

public:
    explicit QQmlAndroidDialog(QObject *parent = 0);

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

#endif // QQMLANDROIDDIALOG_P_H
