#ifndef QTANDROIDALERTDIALOG_P_H
#define QTANDROIDALERTDIALOG_P_H

#include "qtandroiddialog_p.h"

QT_BEGIN_NAMESPACE

class QtAndroidAlertDialog : public QtAndroidDialog
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit QtAndroidAlertDialog(QObject *parent = 0);

    QString title() const;
    void setTitle(const QString &title);

    QString message() const;
    void setMessage(const QString &message);

Q_SIGNALS:
    void titleChanged();
    void messageChanged();

protected:
    QAndroidJniObject onCreate() Q_DECL_OVERRIDE;
    void onInflate(QAndroidJniObject& instance) Q_DECL_OVERRIDE;

private:
    QString m_title;
    QString m_message;
};

QT_END_NAMESPACE

#endif // QTANDROIDALERTDIALOG_P_H
