#include "qqmlandroidcontextual_p.h"
#include "qqmlandroidcontext_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QQmlAndroidContextual::QQmlAndroidContextual(QObject *parent) :
    QQmlAndroidObject(parent), m_context(0)
{
    if (!initContext())
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QQmlAndroidContextual::QQmlAndroidContextual(QQmlAndroidContext* context, QObject *parent) :
    QQmlAndroidObject(parent), m_context(0)
{
    if (!initContext(context))
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QAndroidJniObject QQmlAndroidContextual::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QQmlAndroidContext *QQmlAndroidContextual::context() const
{
    return m_context;
}

void QQmlAndroidContextual::setContext(QQmlAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        propagateContext();
        emit contextChanged();
    }
}

void QQmlAndroidContextual::componentComplete()
{
    QQmlAndroidObject::componentComplete();
    propagateContext();
}

static QQmlAndroidContext *findContext(QQmlAndroidObject *object)
{
    QQmlAndroidContext *context = qobject_cast<QQmlAndroidContext *>(object);
    QObject *p = object->parent();
    while (p && !context) {
        QQmlAndroidContextual *contextual = qobject_cast<QQmlAndroidContextual *>(p);
        if (contextual)
            context = contextual->context();
        p = p->parent();
    }
    return context;
}

bool QQmlAndroidContextual::initContext(QQmlAndroidContext *context)
{
    if (!context)
        context = findContext(this);
    setContext(context);
    return context;
}

void QQmlAndroidContextual::resolveContext()
{
    if (!m_context) {
        setContext(findContext(this));
        if (!m_context)
            qWarning() << "QQmlAndroidContextual: could not resolve context for" << this;
    }
}

void QQmlAndroidContextual::propagateContext()
{
    foreach (QObject *child, children()) {
        QQmlAndroidContextual *contextual = qobject_cast<QQmlAndroidContextual *>(child);
        if (contextual)
            contextual->setContext(m_context);
    }
}

QT_END_NAMESPACE
