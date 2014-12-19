#include "qtqmlandroidobject_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>

QT_BEGIN_NAMESPACE

Q_GLOBAL_STATIC(QReadWriteLock, instanceLock)

QtQmlAndroidObject::QtQmlAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

bool QtQmlAndroidObject::isValid() const
{
    QReadLocker locker(instanceLock());
    return m_instance.isValid();
}

QAndroidJniObject QtQmlAndroidObject::instance() const
{
    QReadLocker locker(instanceLock());
    return m_instance;
}

void QtQmlAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    QWriteLocker locker(instanceLock());
    if (m_instance != instance) {
        m_instance = instance;
        // queue to Qt thread if necessary
        QMetaObject::invokeMethod(this, "changeInstance", Qt::AutoConnection);
    }
}

void QtQmlAndroidObject::changeInstance()
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    objectChange(InstanceChange);
    emit instanceChanged();
}

void QtQmlAndroidObject::construct()
{
    foreach (QObject *obj, children()) {
        QtQmlAndroidObject *child = qobject_cast<QtQmlAndroidObject *>(obj);
        if (child)
            child->construct();
    }

    std::function<void()> method = [=]() {
        inflate(onCreate());
    };

    if (QtQmlAndroid::isMainQtThread())
        QtQmlAndroid::callFunction(method);
    else
        method();
}

void QtQmlAndroidObject::inflate(const QAndroidJniObject &instance)
{
    std::function<void()> method = [=]() {
        QAndroidJniObject object(instance);
        if (object.isValid())
            onInflate(object);
        setInstance(object);
    };

    if (QtQmlAndroid::isMainQtThread())
        QtQmlAndroid::callFunction(method);
    else
        method();
}

void QtQmlAndroidObject::destruct()
{
    foreach (QObject *obj, children()) {
        QtQmlAndroidObject *child = qobject_cast<QtQmlAndroidObject *>(obj);
        if (child)
            child->destruct();
    }

    setInstance(QAndroidJniObject());
}

QAndroidJniObject QtQmlAndroidObject::onCreate()
{
    return QAndroidJniObject();
}

void QtQmlAndroidObject::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());
}

bool QtQmlAndroidObject::isComponentComplete() const
{
    return m_complete;
}

void QtQmlAndroidObject::classBegin()
{
}

void QtQmlAndroidObject::componentComplete()
{
    m_complete = true;
}

void QtQmlAndroidObject::objectChange(ObjectChange change)
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    Q_UNUSED(change);
}

QQmlListProperty<QObject> QtQmlAndroidObject::data()
{
    return QQmlListProperty<QObject>(this, 0, &QtQmlAndroidObject::data_append,
                                     &QtQmlAndroidObject::data_count, &QtQmlAndroidObject::data_at, 0);
}

void QtQmlAndroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QtQmlAndroidObject *that = qobject_cast<QtQmlAndroidObject *>(list->object))
        object->setParent(that);
}

int QtQmlAndroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QtQmlAndroidObject *that = qobject_cast<QtQmlAndroidObject *>(list->object))
        return that->children().count();
    return 0;
}

QObject *QtQmlAndroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QtQmlAndroidObject *that = qobject_cast<QtQmlAndroidObject *>(list->object))
        return that->children().value(index);
    return 0;
}

void QtQmlAndroidObject::childEvent(QChildEvent *event)
{
    if (event->added())
        emit dataChanged();
    else if (event->removed())
        emit dataChanged();
}

QT_END_NAMESPACE
