#include "qtandroidcontextual_p.h"
#include "qtandroidcontext_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qdebug.h>

QtAndroidContextual::QtAndroidContextual(QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
    if (!findContext())
        QCoreApplication::postEvent(this, new QEvent(QEvent::Polish));
}

QtAndroidContextual::QtAndroidContextual(QtAndroidContext* context, QObject *parent) :
    QtAndroidObject(parent), m_context(0)
{
    setContext(context);
    if (!m_context && !findContext())
        QCoreApplication::postEvent(this, new QEvent(QEvent::Polish));
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
        inheritContext();
        emit contextChanged();
    }
}

void QtAndroidContextual::componentComplete()
{
    QtAndroidObject::componentComplete();
    inheritContext();
}

bool QtAndroidContextual::event(QEvent *event)
{
    if (event->type() == QEvent::Polish) {
        if (!m_context) {
            setContext(findContext());
            if (!m_context)
                qWarning() << "QtAndroidContextual: could not find context for" << this;
        }
    }
    return QtAndroidObject::event(event);
}

QtAndroidContext *QtAndroidContextual::findContext()
{
    QtAndroidContext *context = qobject_cast<QtAndroidContext *>(this);
    QObject *p = parent();
    while (p && !context) {
        QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(p);
        if (contextual)
            context = contextual->context();
        p = p->parent();
    }
    return context;
}

void QtAndroidContextual::inheritContext()
{
    foreach (QObject *child, children()) {
        QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(child);
        if (contextual)
            contextual->setContext(m_context);
    }
}
