#ifndef QTQMLANDROIDOBJECT_P_H
#define QTQMLANDROIDOBJECT_P_H

#include "qtqmlandroidglobal_p.h"

#include <QtCore/qobject.h>
#include <QtCore/qreadwritelock.h>
#include <QtQml/qqmllist.h>
#include <QtQml/qqmlparserstatus.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

class QtQmlAndroidObject : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QtQmlAndroidObject(QObject *parent = 0);

    bool isValid() const;
    QAndroidJniObject instance() const;

    void construct();
    void inflate(const QAndroidJniObject &instance);
    void destruct();

    QQmlListProperty<QObject> data();

    enum ObjectChange {
        InstanceChange
    };

Q_SIGNALS:
    void dataChanged();
    void instanceChanged();

protected:
    virtual QAndroidJniObject onCreate();
    virtual void onInflate(QAndroidJniObject &instance);

    bool isComponentComplete() const;
    void classBegin() Q_DECL_OVERRIDE;
    void componentComplete() Q_DECL_OVERRIDE;

    virtual void objectChange(ObjectChange change);

    static void data_append(QQmlListProperty<QObject> *list, QObject *object);
    static int data_count(QQmlListProperty<QObject> *list);
    static QObject *data_at(QQmlListProperty<QObject> *list, int index);

    void childEvent(QChildEvent *event) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void changeInstance();

private:
    void setInstance(const QAndroidJniObject &instance);

    bool m_complete;
    QAndroidJniObject m_instance;
    friend class QtQmlAndroidActivity;
};

QT_END_NAMESPACE

#endif // QTQMLANDROIDOBJECT_P_H
