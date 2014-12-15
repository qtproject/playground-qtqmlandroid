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
        foreach (QObject *child, children()) {
            QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(child);
            if (contextual)
                contextual->setContext(context);
        }
        emit contextChanged();
    }
}

bool QtAndroidContextual::event(QEvent *event)
{
    if (event->type() == QEvent::Polish) {
        if (!findContext())
            qWarning() << "QtAndroidContextual: could not find context for" << this;
    }
    return QtAndroidObject::event(event);
}

bool QtAndroidContextual::findContext()
{
    if (!m_context) {
        QObject *p = parent();
        while (p && !m_context) {
            QtAndroidContextual *contextual = qobject_cast<QtAndroidContextual *>(p);
            if (contextual)
                m_context = contextual->context();
            p = p->parent();
        }
    }
    return m_context;
}
