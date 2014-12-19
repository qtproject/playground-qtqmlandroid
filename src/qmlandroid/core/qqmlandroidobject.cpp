#include "qqmlandroidobject_p.h"
#include "qtqmlandroidfunctions_p.h"
#include <QtCore/qcoreapplication.h>
#include <QtCore/qcoreevent.h>

QT_BEGIN_NAMESPACE

Q_GLOBAL_STATIC(QReadWriteLock, instanceLock)

QQmlAndroidObject::QQmlAndroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

bool QQmlAndroidObject::isValid() const
{
    QReadLocker locker(instanceLock());
    return m_instance.isValid();
}

QAndroidJniObject QQmlAndroidObject::instance() const
{
    QReadLocker locker(instanceLock());
    return m_instance;
}

void QQmlAndroidObject::setInstance(const QAndroidJniObject &instance)
{
    QWriteLocker locker(instanceLock());
    if (m_instance != instance) {
        m_instance = instance;
        // queue to Qt thread if necessary
        QMetaObject::invokeMethod(this, "changeInstance", Qt::AutoConnection);
    }
}

void QQmlAndroidObject::changeInstance()
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    objectChange(InstanceChange);
    emit instanceChanged();
}

void QQmlAndroidObject::construct()
{
    foreach (QObject *obj, children()) {
        QQmlAndroidObject *child = qobject_cast<QQmlAndroidObject *>(obj);
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

void QQmlAndroidObject::inflate(const QAndroidJniObject &instance)
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

void QQmlAndroidObject::destruct()
{
    foreach (QObject *obj, children()) {
        QQmlAndroidObject *child = qobject_cast<QQmlAndroidObject *>(obj);
        if (child)
            child->destruct();
    }

    setInstance(QAndroidJniObject());
}

QAndroidJniObject QQmlAndroidObject::onCreate()
{
    return QAndroidJniObject();
}

void QQmlAndroidObject::onInflate(QAndroidJniObject &instance)
{
    Q_UNUSED(instance);
    Q_ASSERT(!QtQmlAndroid::isMainQtThread());
}

bool QQmlAndroidObject::isComponentComplete() const
{
    return m_complete;
}

void QQmlAndroidObject::classBegin()
{
}

void QQmlAndroidObject::componentComplete()
{
    m_complete = true;
}

void QQmlAndroidObject::objectChange(ObjectChange change)
{
    Q_ASSERT(QtQmlAndroid::isMainQtThread());
    Q_UNUSED(change);
}

QQmlListProperty<QObject> QQmlAndroidObject::data()
{
    return QQmlListProperty<QObject>(this, 0, &QQmlAndroidObject::data_append,
                                     &QQmlAndroidObject::data_count, &QQmlAndroidObject::data_at, 0);
}

void QQmlAndroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        object->setParent(that);
}

int QQmlAndroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        return that->children().count();
    return 0;
}

QObject *QQmlAndroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QQmlAndroidObject *that = qobject_cast<QQmlAndroidObject *>(list->object))
        return that->children().value(index);
    return 0;
}

void QQmlAndroidObject::childEvent(QChildEvent *event)
{
    if (event->added())
        emit dataChanged();
    else if (event->removed())
        emit dataChanged();
}

QT_END_NAMESPACE
