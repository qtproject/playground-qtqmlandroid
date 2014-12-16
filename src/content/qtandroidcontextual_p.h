#ifndef QTANDROIDCONTEXTUAL_P_H
#define QTANDROIDCONTEXTUAL_P_H

#include "qtandroidobject_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>

QT_BEGIN_NAMESPACE

class QtAndroidContext;

class QtAndroidContextual : public QtAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtAndroidContext *context READ context NOTIFY contextChanged)

public:
    explicit QtAndroidContextual(QObject *parent = 0);
    explicit QtAndroidContextual(QtAndroidContext *context, QObject *parent = 0);

    QAndroidJniObject ctx() const;
    QtAndroidContext *context() const;
    void setContext(QtAndroidContext *context);

Q_SIGNALS:
    void contextChanged();

protected:
    void componentComplete() Q_DECL_OVERRIDE;
    bool event(QEvent *event) Q_DECL_OVERRIDE;

private:
    QtAndroidContext *findContext();
    void inheritContext();

    QtAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QTANDROIDCONTEXTUAL_P_H
