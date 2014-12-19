#ifndef QTQMLANDROIDCONTEXTUAL_P_H
#define QTQMLANDROIDCONTEXTUAL_P_H

#include "qtqmlandroidobject_p.h"

QT_BEGIN_NAMESPACE

class QtQmlAndroidContext;

class QtQmlAndroidContextual : public QtQmlAndroidObject
{
    Q_OBJECT
    Q_PROPERTY(QtQmlAndroidContext *context READ context NOTIFY contextChanged)

public:
    explicit QtQmlAndroidContextual(QObject *parent = 0);
    explicit QtQmlAndroidContextual(QtQmlAndroidContext *context, QObject *parent = 0);

    QAndroidJniObject ctx() const;
    QtQmlAndroidContext *context() const;
    void setContext(QtQmlAndroidContext *context);

Q_SIGNALS:
    void contextChanged();

protected:
    void componentComplete() Q_DECL_OVERRIDE;

private Q_SLOTS:
    bool initContext(QtQmlAndroidContext *context = 0);
    void resolveContext();
    void propagateContext();

private:
    QtQmlAndroidContext *m_context;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDCONTEXTUAL_P_H
