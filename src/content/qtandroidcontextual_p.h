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

    QAndroidJniObject ctx() const;
    QtAndroidContext *context() const;
    void setContext(QtAndroidContext *context);

Q_SIGNALS:
    void contextChanged();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;

private:
    bool findContext();

    QtAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QTANDROIDCONTEXTUAL_P_H
