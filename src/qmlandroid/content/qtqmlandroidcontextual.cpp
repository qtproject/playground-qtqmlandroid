#include "qtqmlandroidcontextual_p.h"
#include "qtqmlandroidcontext_p.h"
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

QtQmlAndroidContextual::QtQmlAndroidContextual(QObject *parent) :
    QtQmlAndroidObject(parent), m_context(0)
{
    if (!initContext())
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QtQmlAndroidContextual::QtQmlAndroidContextual(QtQmlAndroidContext* context, QObject *parent) :
    QtQmlAndroidObject(parent), m_context(0)
{
    if (!initContext(context))
        QMetaObject::invokeMethod(this, "resolveContext", Qt::QueuedConnection);
}

QAndroidJniObject QtQmlAndroidContextual::ctx() const
{
    if (!m_context)
        return QAndroidJniObject();
    return m_context->instance();
}

QtQmlAndroidContext *QtQmlAndroidContextual::context() const
{
    return m_context;
}

void QtQmlAndroidContextual::setContext(QtQmlAndroidContext *context)
{
    if (m_context != context) {
        m_context = context;
        propagateContext();
        emit contextChanged();
    }
}

void QtQmlAndroidContextual::componentComplete()
{
    QtQmlAndroidObject::componentComplete();
    propagateContext();
}

static QtQmlAndroidContext *findContext(QtQmlAndroidObject *object)
{
    QtQmlAndroidContext *context = qobject_cast<QtQmlAndroidContext *>(object);
    QObject *p = object->parent();
    while (p && !context) {
        QtQmlAndroidContextual *contextual = qobject_cast<QtQmlAndroidContextual *>(p);
        if (contextual)
            context = contextual->context();
        p = p->parent();
    }
    return context;
}

bool QtQmlAndroidContextual::initContext(QtQmlAndroidContext *context)
{
    if (!context)
        context = findContext(this);
    setContext(context);
    return context;
}

void QtQmlAndroidContextual::resolveContext()
{
    if (!m_context) {
        setContext(findContext(this));
        if (!m_context)
            qWarning() << "QtQmlAndroidContextual: could not resolve context for" << this;
    }
}

void QtQmlAndroidContextual::propagateContext()
{
    foreach (QObject *child, children()) {
        QtQmlAndroidContextual *contextual = qobject_cast<QtQmlAndroidContextual *>(child);
        if (contextual)
            contextual->setContext(m_context);
    }
}

QT_END_NAMESPACE
