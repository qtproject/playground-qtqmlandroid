#include "qtandroidobject_p.h"
#include <QtCore/qcoreevent.h>
#include <QtCore/qcoreapplication.h>

QtAndroidObject::QtAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
    QCoreApplication::postEvent(this, new QEvent(QEvent::Polish));
}

QAndroidJniObject QtAndroidObject::instance() const
{
    return m_instance;
}

void QtAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    m_instance = instance;
}

bool QtAndroidObject::isComponentComplete() const
{
    return m_complete;
}

void QtAndroidObject::classBegin()
{
}

void QtAndroidObject::componentComplete()
{
    m_complete = true;
}

QQmlListProperty<QObject> QtAndroidObject::data()
{
    return QQmlListProperty<QObject>(this, 0, &QtAndroidObject::data_append,
                                     &QtAndroidObject::data_count, &QtAndroidObject::data_at, 0);
}

void QtAndroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QtAndroidObject *that = qobject_cast<QtAndroidObject *>(list->object))
        object->setParent(that);
}

int QtAndroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QtAndroidObject *that = qobject_cast<QtAndroidObject *>(list->object))
        return that->children().count();
    return 0;
}

QObject *QtAndroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QtAndroidObject *that = qobject_cast<QtAndroidObject *>(list->object))
        return that->children().value(index);
    return 0;
}

void QtAndroidObject::childEvent(QChildEvent *event)
{
    if (event->added())
        emit dataChanged();
    else if (event->removed())
        emit dataChanged();
}
