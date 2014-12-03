#include "qtdroidobject_p.h"
#include <QtCore/qcoreevent.h>
#include <QtCore/qcoreapplication.h>

QtDroidObject::QtDroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
    QCoreApplication::postEvent(this, new QEvent(QEvent::Polish));
}

QAndroidJniObject QtDroidObject::instance() const
{
    return m_instance;
}

void QtDroidObject::setInstance(const QAndroidJniObject &instance)
{
    m_instance = instance;
}

bool QtDroidObject::isComponentComplete() const
{
    return m_complete;
}

void QtDroidObject::classBegin()
{
}

void QtDroidObject::componentComplete()
{
    m_complete = true;
}

QQmlListProperty<QObject> QtDroidObject::data()
{
    return QQmlListProperty<QObject>(this, 0, &QtDroidObject::data_append,
                                     &QtDroidObject::data_count, &QtDroidObject::data_at, 0);
}

void QtDroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object))
        object->setParent(that);
}

int QtDroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object))
        return that->children().count();
    return 0;
}

QObject *QtDroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object))
        return that->children().value(index);
    return 0;
}

void QtDroidObject::childEvent(QChildEvent *event)
{
    if (event->added())
        emit dataChanged();
    else if (event->removed())
        emit dataChanged();
}
