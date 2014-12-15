#include "qtandroidobject_p.h"
#include "qtandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>

QtAndroidObject::QtAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

bool QtAndroidObject::isValid() const
{
    // TODO: mutex/read-write lock
    return m_instance.isValid();
}

QAndroidJniObject QtAndroidObject::instance() const
{
    // TODO: mutex/read-write lock
    return m_instance;
}

void QtAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    // TODO: mutex/read-write lock
    if (m_instance != instance) {
        m_instance = instance;
        // queue to Qt thread if necessary
        QMetaObject::invokeMethod(this, "instanceChanged", Qt::AutoConnection);
    }
}

void QtAndroidObject::construct()
{
    foreach (QObject *obj, children()) {
        QtAndroidObject *child = qobject_cast<QtAndroidObject *>(obj);
        if (child)
            child->construct();
    }

    std::function<void()> method = [=]() {
        QAndroidJniObject instance = onCreate();
        if (instance.isValid())
            onInflate(instance);
        setInstance(instance);
    };

    if (QtAndroid::isMainQtThread())
        QtAndroid::callFunction(method);
    else
        method();
}

void QtAndroidObject::destruct()
{
    foreach (QObject *obj, children()) {
        QtAndroidObject *child = qobject_cast<QtAndroidObject *>(obj);
        if (child)
            child->destruct();
    }

    setInstance(QAndroidJniObject());
}

QAndroidJniObject QtAndroidObject::onCreate()
{
    return QAndroidJniObject();
}

void QtAndroidObject::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
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
