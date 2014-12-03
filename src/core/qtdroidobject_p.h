#ifndef QTDROIDOBJECT_P_H
#define QTDROIDOBJECT_P_H

#include <QtCore/qobject.h>
#include <QtQml/qqmllist.h>
#include <QtQml/qqmlparserstatus.h>
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QT_BEGIN_NAMESPACE

class QtDroidObject : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QObject> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit QtDroidObject(QObject *parent = 0);

    QAndroidJniObject instance() const;
    void setInstance(const QAndroidJniObject &instance);

    QQmlListProperty<QObject> data();

Q_SIGNALS:
    void dataChanged();

protected:
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

#endif // QTDROIDOBJECT_P_H
