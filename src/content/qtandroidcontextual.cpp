#include "qtandroidcontextual_p.h"
#include "qtandroidcontext_p.h"
#include <QtCore/qdebug.h>

QtAndroidContextual::QtAndroidContextual(QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
    if (!initContext())
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QtAndroidContextual::QtAndroidContextual(QtAndroidContext* context, QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
    if (!initContext(context))
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QAndroidJniObject QtAndroidContextual::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QtAndroidContext *QtAndroidContextual::context() const
{
    return m_context;
}

void QtAndroidContextual::setContext(QtAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        propagateContext();
        emit contextChanged();
    }
}

void QtAndroidContextual::componentComplete()
{
    QtAndroidObject::componentComplete();
    propagateContext();
}

static QtAndroidContext *findContext(QtAndroidObject *object)
{
    QtAndroidContext *context = qobject_cast<QtAndroidContext *>(object);
    QObject *p = object->parent();
    while (p && !context) {
        QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(p);
        if (contextual)
            context = contextual->context();
        p = p->parent();
    }
    return context;
}

bool QtAndroidContextual::initContext(QtAndroidContext *context)
{
    if (!context)
        context = findContext(this);
    setContext(context);
    return context;
}

void QtAndroidContextual::resolveContext()
{
    if (!m_context) {
        setContext(findContext(this));
        if (!m_context)
            qWarning() << "QtAndroidContextual: could not resolve context for" << this;
    }
}

void QtAndroidContextual::propagateContext()
{
    foreach (QObject *child, children()) {
        QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(child);
        if (contextual)
            contextual->setContext(m_context);
    }
}
