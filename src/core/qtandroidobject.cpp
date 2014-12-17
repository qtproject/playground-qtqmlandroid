#include "qtandroidobject_p.h"
#include "qtandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>

Q_GLOBAL_STATIC(QReadWriteLock, instanceLock)

QtAndroidObject::QtAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

bool QtAndroidObject::isValid() const
{
    QReadLocker locker(instanceLock());
    return m_instance.isValid();
}

QAndroidJniObject QtAndroidObject::instance() const
{
    QReadLocker locker(instanceLock());
    return m_instance;
}

void QtAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    QWriteLocker locker(instanceLock());
    if (m_instance != instance) {
        m_instance = instance;
        // queue to Qt thread if necessary
        QMetaObject::invokeMethod(this, "changeInstance", Qt::AutoConnection);
    }
}

void QtAndroidObject::changeInstance()
{
    Q_ASSERT(QtAndroid::isMainQtThread());
    objectChange(InstanceChange);
    emit instanceChanged();
}

void QtAndroidObject::construct()
{
    foreach (QObject *obj, children()) {
        QtAndroidObject *child = qobject_cast<QtAndroidObject *>(obj);
        if (child)
            child->construct();
    }

    std::function<void()> method = [=]() {
        inflate(onCreate());
    };

    if (QtAndroid::isMainQtThread())
        QtAndroid::callFunction(method);
    else
        method();
}

void QtAndroidObject::inflate(const QAndroidJniObject &instance)
{
    std::function<void()> method = [=]() {
        QAndroidJniObject object(instance);
        if (object.isValid())
            onInflate(object);
        setInstance(object);
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
    Q_ASSERT(!QtAndroid::isMainQtThread());
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

void QtAndroidObject::objectChange(ObjectChange change)
{
    Q_ASSERT(QtAndroid::isMainQtThread());
    Q_UNUSED(change);
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
