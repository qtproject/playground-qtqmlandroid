#include "qtdroidobject_p.h"
#include <QtCore/private/qjnihelpers_p.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QtAndroidExtras/qandroidfunctions.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QtDroidObject::QtDroidObject(QObject *parent) :
    QObject(parent), m_complete(false)
{
}

QAndroidJniObject QtDroidObject::instance() const
{
    return m_instance;
}

void QtDroidObject::setInstance(const QAndroidJniObject &instance)
{
    m_instance = instance;
}

void QtDroidObject::callFunction(std::function<void()> method)
{
    QAndroidJniEnvironment env;
    QRunnable *runnable = new QtConcurrent::StoredFunctorCall0<void, decltype(method)>(method);
    QtAndroidPrivate::runOnUiThread(runnable, env);
}

void QtDroidObject::callTextMethod(const char *method, const QString &text)
{
    QAndroidJniObject obj = instance();
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Ljava/lang/CharSequence;)V", QAndroidJniObject::fromString(text).object());
        });
    }
}

void QtDroidObject::callRealMethod(const char *method, qreal value)
{
    QAndroidJniObject obj = instance();
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(F)V", value);
        });
    }
}

void QtDroidObject::callIntMethod(const char *method, int value)
{
    QAndroidJniObject obj = instance();
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(I)V", value);
        });
    }
}

void QtDroidObject::callBoolMethod(const char *method, bool value)
{
    QAndroidJniObject obj = instance();
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method, "(Z)V", value);
        });
    }
}

void QtDroidObject::callVoidMethod(const char *method)
{
    QAndroidJniObject obj = instance();
    if (obj.isValid()) {
        callFunction([=]() {
            obj.callMethod<void>(method);
        });
    }
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
    return QQmlListProperty<QObject>(this, 0, &QtDroidObject::data_append, &QtDroidObject::data_count,
                                              &QtDroidObject::data_at, &QtDroidObject::data_clear);
}

void QtDroidObject::data_append(QQmlListProperty<QObject> *list, QObject *object)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object)) {
        object->setParent(that);
        that->m_data.append(object);
        that->objectAdded(object);
        emit that->dataChanged();
    }
}

int QtDroidObject::data_count(QQmlListProperty<QObject> *list)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object))
        return that->m_data.count();
    return 0;
}

QObject *QtDroidObject::data_at(QQmlListProperty<QObject> *list, int index)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object))
        return that->m_data.at(index);
    return 0;
}

void QtDroidObject::data_clear(QQmlListProperty<QObject> *list)
{
    if (QtDroidObject *that = qobject_cast<QtDroidObject *>(list->object)) {
        that->m_data.clear();
        emit that->dataChanged();
    }
}
