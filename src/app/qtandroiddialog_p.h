#ifndef QTANDROIDDIALOG_P_H
#define QTANDROIDDIALOG_P_H

#include "qtandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidContext;

class QtAndroidDialog : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidContext *context READ context WRITE setContext NOTIFY contextChanged)

public:
    explicit QtAndroidDialog(QObject *parent = 0);

    QAndroidJniObject ctx() const;
    QtAndroidContext *context() const;
    void setContext(QtAndroidContext *context);

public Q_SLOTS:
    void cancel();
    void dismiss();
    void hide();
    void show();

Q_SIGNALS:
    void contextChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

private:
    QtAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QTANDROIDDIALOG_P_H
