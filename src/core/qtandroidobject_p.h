#ifndef QTANDROIDOBJECT_P_H
#define QTANDROIDOBJECT_P_H

#include "qtandroidglobal_p.h"

#include <QtCore/qobject.h>
#include <QtCore/qreadwritelock.h>
#include <QtQml/qqmllist.h>
#include <QtQml/qqmlparserstatus.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

class QtAndroidObject : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QtAndroidObject(QObject *parent = 0);

    bool isValid() const;
    QAndroidJniObject instance() const;
    void setInstance(const QAndroidJniObject &instance); // TODO: private

    void construct();
    void destruct();

    QQmlListProperty<QObject> data();

Q_SIGNALS:
    void dataChanged();
    void instanceChanged();

protected:
    virtual QAndroidJniObject onCreate();
    virtual void onInflate(QAndroidJniObject &instance);

    bool isComponentComplete() const;
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

    static void data_append(QQmlListProperty<QObject> *list, QObject *object);
    static int data_count(QQmlListProperty<QObject> *list);
    static QObject *data_at(QQmlListProperty<QObject> *list, int index);

    void childEvent(QChildEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_complete;
    QAndroidJniObject m_instance;
};

QT_END_NAMESPACE

#endif // QTANDROIDOBJECT_P_H
